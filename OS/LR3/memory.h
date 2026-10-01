#ifndef MEMORY_H
#define MEMORY_H

#define PAGE_SIZE 256
#define PHYS_MEM_SIZE 65536
#define VIRT_MEM_SIZE 65536

#define NUM_PHYS_FRAMES (PHYS_MEM_SIZE / PAGE_SIZE)
#define NUM_VIRT_PAGES  (VIRT_MEM_SIZE / PAGE_SIZE)

extern unsigned char phys_mem[PHYS_MEM_SIZE];
extern int page_table[NUM_VIRT_PAGES];
extern int frame_used[NUM_PHYS_FRAMES];

void init(void);
int alloc(int size);
void free_block(int virt_addr, int size);
void write_mem(int virt_addr, unsigned char *buffer, int size);
void read_mem(int virt_addr, unsigned char *buffer, int size);

#endif