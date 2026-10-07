#pragma once
#include <iostream>
#include <cstring>

const int BLOCK_SIZE = 10;
const int MAX_BLOCKS = 100;
const int MAX_FILES = 20;
const int NAME_LEN = 32;

struct Block{ char data[BLOCK_SIZE]; int nextBlock; };
struct FileEntry{ char name[NAME_LEN]; int firstBlock; int size; bool isUsed; };

extern Block disk[MAX_BLOCKS];
extern FileEntry directory[MAX_FILES];

void init_fs();
int allocate_block();
void free_chain(int start_block);
void create_file(const char* name);
void write_to_file(const char* name, const char* data);
void read_file(const char* name);
void delete_file(const char* name);
void copy_file(const char* src, const char* dst);
void move_file(const char* src, const char* dst);
void dump_fs();