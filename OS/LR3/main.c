#include "memory.h"
#include <stdio.h>

static void experiment_fragmentation(void) {
    printf("\nExperiment 1: internal fragmentation\n");
    printf("Size | Pages | Used | Wasted\n");

    for (int size = 1; size <= 512; size += 16) {
        init();
        int addr = alloc(size);
        if (addr == -1) {
            printf("%6d | ERROR\n", size);
            continue;
        }
        int pages = (size + PAGE_SIZE - 1) / PAGE_SIZE;
        int used = pages * PAGE_SIZE;
        int wasted = used - size;
        printf("%6d | %7d | %6d | %8d\n", size, pages, used, wasted);
        free_block(addr, size);
    }
}

int main(void) {
    experiment_fragmentation();
    return 0;
}