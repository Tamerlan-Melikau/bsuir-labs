#include "memory.h"
#include <string.h>

unsigned char phys_mem[PHYS_MEM_SIZE];
int page_table[NUM_VIRT_PAGES];
int frame_used[NUM_PHYS_FRAMES];

void init(void) {
    memset(phys_mem, 0, sizeof(phys_mem));
    memset(frame_used, 0, sizeof(frame_used));
    for (int i = 0; i < NUM_VIRT_PAGES; i++) {
        page_table[i] = -1;
    }
}

int alloc(int size) {
    if (size <= 0) return -1;

    int pages_needed = (size + PAGE_SIZE - 1) / PAGE_SIZE;

    int free_pages = 0;
    for (int i = 0; i < NUM_VIRT_PAGES; i++) {
        if (page_table[i] == -1) free_pages++;
    }
    if (free_pages < pages_needed) return -1;

    int free_frames = 0;
    for (int i = 0; i < NUM_PHYS_FRAMES; i++) {
        if (frame_used[i] == 0) free_frames++;
    }
    if (free_frames < pages_needed) return -1;

    int first_page = -1;
    int count = 0;
    for (int i = 0; i < NUM_VIRT_PAGES; i++) {
        if (page_table[i] == -1) {
            if (count == 0) first_page = i;
            count++;
            if (count == pages_needed) break;
        } else {
            count = 0;
            first_page = -1;
        }
    }
    if (first_page == -1) return -1;

    for (int p = 0; p < pages_needed; p++) {
        int page = first_page + p;
        int frame = -1;
        for (int f = 0; f < NUM_PHYS_FRAMES; f++) {
            if (frame_used[f] == 0) {
                frame = f;
                break;
            }
        }
        page_table[page] = frame;
        frame_used[frame] = 1;
    }

    return first_page * PAGE_SIZE;
}

void free_block(int virt_addr, int size) {
    if (size <= 0) return;
    if (virt_addr < 0 || virt_addr >= VIRT_MEM_SIZE) return;

    int first_page = virt_addr / PAGE_SIZE;
    int pages_to_free = (size + PAGE_SIZE - 1) / PAGE_SIZE;

    for (int p = 0; p < pages_to_free; p++) {
        int page = first_page + p;
        if (page >= NUM_VIRT_PAGES) break;

        int frame = page_table[page];
        if (frame == -1) continue;

        frame_used[frame] = 0;
        page_table[page] = -1;
        memset(&phys_mem[frame * PAGE_SIZE], 0, PAGE_SIZE);
    }
}

void write_mem(int virt_addr, unsigned char *buffer, int size) {
    if (buffer == NULL) return;
    if (size <= 0) return;
    if (virt_addr < 0) return;
    if (virt_addr + size > VIRT_MEM_SIZE) return;

    for (int i = 0; i < size; i++) {
        int cur_virt = virt_addr + i;
        int page = cur_virt / PAGE_SIZE;
        int offset = cur_virt % PAGE_SIZE;

        int frame = page_table[page];
        if (frame == -1) return;

        int phys = frame * PAGE_SIZE + offset;
        phys_mem[phys] = buffer[i];
    }
}

void read_mem(int virt_addr, unsigned char *buffer, int size) {
    if (buffer == NULL) return;
    if (size <= 0) return;
    if (virt_addr < 0) return;
    if (virt_addr + size > VIRT_MEM_SIZE) return;

    for (int i = 0; i < size; i++) {
        int cur_virt = virt_addr + i;
        int page = cur_virt / PAGE_SIZE;
        int offset = cur_virt % PAGE_SIZE;

        int frame = page_table[page];
        if (frame == -1) return;

        int phys = frame * PAGE_SIZE + offset;
        buffer[i] = phys_mem[phys];
    }
}