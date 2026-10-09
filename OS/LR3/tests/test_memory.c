#include "../memory.h"
#include <stdio.h>
#include <string.h>

static int passed = 0;
static int failed = 0;

#define TEST(name, cond) do { \
    if (cond) { printf("[PASS] %s\n", name); passed++; } \
    else { printf("[FAIL] %s\n", name); failed++; } \
} while(0)

static void test_init(void) {
    printf("\n--- init ---\n");
    init();
    int ok = 1;
    for (int i = 0; i < NUM_VIRT_PAGES; i++) if (page_table[i] != -1) ok = 0;
    TEST("init: pages unallocated", ok);

    ok = 1;
    for (int i = 0; i < NUM_PHYS_FRAMES; i++) if (frame_used[i] != 0) ok = 0;
    TEST("init: frames free", ok);

    ok = 1;
    for (int i = 0; i < PHYS_MEM_SIZE; i++) if (phys_mem[i] != 0) ok = 0;
    TEST("init: memory zeroed", ok);
}

static void test_alloc_invalid(void) {
    printf("\n--- alloc invalid ---\n");
    init();
    TEST("alloc(0)", alloc(0) == -1);
    TEST("alloc(-1)", alloc(-1) == -1);
    TEST("alloc(-100)", alloc(-100) == -1);
}

static void test_alloc_basic(void) {
    printf("\n--- alloc basic ---\n");
    init();
    TEST("alloc(1) -> 0", alloc(1) == 0);
    TEST("alloc(PAGE_SIZE) -> PAGE_SIZE", alloc(PAGE_SIZE) == PAGE_SIZE);
    TEST("alloc(PAGE_SIZE+1) -> 2*PAGE_SIZE", alloc(PAGE_SIZE + 1) == 2 * PAGE_SIZE);
    TEST("alloc(2*PAGE_SIZE) -> 4*PAGE_SIZE", alloc(2 * PAGE_SIZE) == 4 * PAGE_SIZE);
}

static void test_alloc_full(void) {
    printf("\n--- alloc until full ---\n");
    init();
    int count = 0;
    while (alloc(PAGE_SIZE) != -1) count++;
    TEST("filled NUM_VIRT_PAGES pages", count == NUM_VIRT_PAGES);
    TEST("alloc after full -> -1", alloc(PAGE_SIZE) == -1);

    int ok = 1;
    for (int i = 0; i < NUM_PHYS_FRAMES; i++) if (frame_used[i] == 0) ok = 0;
    TEST("all frames used", ok);
}

static void test_alloc_too_big(void) {
    printf("\n--- alloc too big ---\n");
    init();
    TEST("alloc(VIRT_MEM_SIZE+1) -> -1", alloc(VIRT_MEM_SIZE + 1) == -1);
    TEST("alloc(VIRT_MEM_SIZE) -> 0", alloc(VIRT_MEM_SIZE) == 0);
}

static void test_free_basic(void) {
    printf("\n--- free basic ---\n");
    init();
    int a = alloc(PAGE_SIZE);
    free_block(a, PAGE_SIZE);
    TEST("page_table reset", page_table[0] == -1);
    TEST("frame_used reset", frame_used[0] == 0);
    int d = alloc(PAGE_SIZE);
    TEST("reuse same address", d == a);
}

static void test_free_multiple(void) {
    printf("\n--- free multiple ---\n");
    init();
    int a = alloc(3 * PAGE_SIZE);
    TEST("alloc 3 pages at 0", a == 0);
    free_block(a, 3 * PAGE_SIZE);
    TEST("page 0 free", page_table[0] == -1);
    TEST("page 1 free", page_table[1] == -1);
    TEST("page 2 free", page_table[2] == -1);
}

static void test_free_invalid(void) {
    printf("\n--- free invalid ---\n");
    init();
    free_block(-1, PAGE_SIZE);
    free_block(VIRT_MEM_SIZE, PAGE_SIZE);
    free_block(0, 0);
    free_block(0, -5);
    TEST("invalid free no crash", 1);
}

static void test_free_double(void) {
    printf("\n--- free double ---\n");
    init();
    int a = alloc(PAGE_SIZE);
    free_block(a, PAGE_SIZE);
    free_block(a, PAGE_SIZE);
    TEST("double free no crash", 1);
}

static void test_write_read_basic(void) {
    printf("\n--- write/read basic ---\n");
    init();
    int a = alloc(10);
    unsigned char w[] = "Hello";
    unsigned char r[10] = {0};
    write_mem(a, w, 5);
    read_mem(a, r, 5);
    TEST("5 bytes match", memcmp(w, r, 5) == 0);
}

static void test_write_read_all(void) {
    printf("\n--- write/read all bytes ---\n");
    init();
    int a = alloc(256);
    unsigned char w[256], r[256];
    for (int i = 0; i < 256; i++) w[i] = (unsigned char)i;
    write_mem(a, w, 256);
    read_mem(a, r, 256);
    TEST("all 256 bytes match", memcmp(w, r, 256) == 0);
}

static void test_write_read_cross(void) {
    printf("\n--- write/read cross page ---\n");
    init();
    int a = alloc(2 * PAGE_SIZE);
    unsigned char w[300], r[300] = {0};
    for (int i = 0; i < 300; i++) w[i] = (unsigned char)(i % 256);
    write_mem(a + PAGE_SIZE - 100, w, 300);
    read_mem(a + PAGE_SIZE - 100, r, 300);
    TEST("cross boundary match", memcmp(w, r, 300) == 0);
}

static void test_write_read_invalid(void) {
    printf("\n--- write/read invalid ---\n");
    init();
    unsigned char buf[10] = {0};
    write_mem(0, NULL, 10);
    read_mem(0, NULL, 10);
    TEST("NULL buffer no crash", 1);
    write_mem(0, buf, 0);
    read_mem(0, buf, 0);
    TEST("zero size no crash", 1);
    write_mem(0, buf, -1);
    read_mem(0, buf, -1);
    TEST("negative size no crash", 1);
    write_mem(VIRT_MEM_SIZE, buf, 10);
    read_mem(VIRT_MEM_SIZE, buf, 10);
    TEST("out of bounds no crash", 1);
}

static void test_write_unallocated(void) {
    printf("\n--- write unallocated ---\n");
    init();
    unsigned char w = 42, r = 0;
    write_mem(0, &w, 1);
    read_mem(0, &r, 1);
    TEST("write ignored on unallocated", r == 0);
}

static void test_multiple_blocks(void) {
    printf("\n--- multiple blocks ---\n");
    init();
    int a = alloc(PAGE_SIZE);
    int b = alloc(PAGE_SIZE);
    int c = alloc(PAGE_SIZE);
    unsigned char va = 11, vb = 22, vc = 33;
    write_mem(a, &va, 1);
    write_mem(b, &vb, 1);
    write_mem(c, &vc, 1);
    unsigned char ra = 0, rb = 0, rc = 0;
    read_mem(a, &ra, 1);
    read_mem(b, &rb, 1);
    read_mem(c, &rc, 1);
    TEST("block A ok", ra == 11);
    TEST("block B ok", rb == 22);
    TEST("block C ok", rc == 33);
}

static void test_free_reuse(void) {
    printf("\n--- free middle and reuse ---\n");
    init();
    alloc(PAGE_SIZE);
    int b = alloc(PAGE_SIZE);
    alloc(PAGE_SIZE);
    free_block(b, PAGE_SIZE);
    int d = alloc(PAGE_SIZE);
    TEST("reuse freed address", d == b);
}

int main(void) {
    test_init();
    test_alloc_invalid();
    test_alloc_basic();
    test_alloc_full();
    test_alloc_too_big();
    test_free_basic();
    test_free_multiple();
    test_free_invalid();
    test_free_double();
    test_write_read_basic();
    test_write_read_all();
    test_write_read_cross();
    test_write_read_invalid();
    test_write_unallocated();
    test_multiple_blocks();
    test_free_reuse();

    printf("\n=================\n");
    printf("PASSED: %d\n", passed);
    printf("FAILED: %d\n", failed);
    printf("=================\n");

    return failed == 0 ? 0 : 1;
}