#include <iostream>
#include <string>

const int BLOCK_SIZE = 64;
const int MAX_BLOCKS = 100;
const int MAX_FILES = 20;
const int NAME_LEN = 32;

struct Block{
    char data[BLOCK_SIZE];
    int nextBlock;
};

struct FileEntry{
    char name[NAME_LEN];
    int firstBlock;
    int size;
    bool isUsed;
};

Block disk[MAX_BLOCKS];
FileEntry directory[MAX_FILES];

void init_fs(){
    for(int i = 0; i < MAX_BLOCKS; ++i){
        disk[i].nextBlock = -2;
        disk[i].data[0] = '\0';
    }

    for(int i = 0; i < MAX_FILES; ++i){
        directory[i].isUsed = false;
        directory[i].firstBlock = -1;
        directory[i].size = 0;
        directory[i].name[0] = '\0';
    }
}

int allocate_block(){
    for(int i = 0; i < MAX_BLOCKS; ++i){
        if(disk[i].nextBlock == -2){
            disk[i].nextBlock = -1;
            disk[i].data[0] = '\0';
            return i;
        }
    }
    return -1;
}

void free_chain(int start_block){
    int current = start_block;
    while(current != -1){
        int next = disk[current].nextBlock;
        disk[current].nextBlock = -2;
        disk[current].data[0] = '\0';
        current = next;
    }
}

void create_file(const char* name){
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, name) == 0){
            std::cout << "Error: file exists\n";
            return;
        }
    }

    int slot = -1;
    for(int i = 0; i < MAX_FILES; ++i){
        if(!directory[i].isUsed){
            slot = i; 
            break;
        }
    }
    if(slot == -1){
        std::cout << "Error: directory full\n"; 
        return;
    }
    int b = allocate_block();
    if(b == -1){
        std::cout << "Error: disk full\n";
        return;
    }
    strncpy(directory[slot].name, name, NAME_LEN - 1);
    directory[slot].name[NAME_LEN - 1] = '\0';
    directory[slot].firstBlock = b;
    directory[slot].size = 0;
    directory[slot].isUsed = true;
}

void write_to_file(const char* name, const char* data){
    int slot = -1;
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, name) == 0){
            slot = i;
            break;
        }
    }
    if(slot == -1){
        std::cout << "Error: no such file\n";
        return;
    }

    int current = directory[slot].firstBlock;
    while(disk[current].nextBlock != -1){
        current = disk[current].nextBlock;
    }

    int offset = directory[slot].size % BLOCK_SIZE;

    int written = 0;
    int len = strlen(data);
    while(written < len){
        if(offset == BLOCK_SIZE){
            int nb = allocate_block();
            if(nb == -1){
                std::cout << "Error: disk full\n";
                return;
            }
            disk[current].nextBlock = nb;
            current = nb;
            offset = 0;
        }
        disk[current].data[offset] = data[written];
        ++offset;
        ++written;
        ++directory[slot].size;
    }
}