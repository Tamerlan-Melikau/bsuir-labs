#include "fs.h"

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
        if(offset == BLOCK_SIZE || (offset == 0 && directory[slot].size > 0)){
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

void read_file(const char* name){
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
    int read = 0;
    while(read < directory[slot].size){
        int to_read = directory[slot].size - read;
        if(to_read > BLOCK_SIZE){
            to_read = BLOCK_SIZE;
        }
        std::cout.write(disk[current].data, to_read);
        read += to_read;
        current = disk[current].nextBlock;
    }
    std::cout << "\n";
}

void delete_file(const char* name){
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
    free_chain(directory[slot].firstBlock);
    directory[slot].isUsed = false;
    directory[slot].firstBlock = -1;
    directory[slot].size = 0;
    directory[slot].name[0] = '\0';
}

void copy_file(const char* src, const char* dst){
    int src_slot = -1;
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, src) == 0){
            src_slot = i;
            break;
        }
    }
    if(src_slot == -1){
        std::cout << "Error: source not found\n";
        return;
    }
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, dst) == 0){
            std::cout << "Error: destination exists\n";
            return;
        }
    }
    char buffer[MAX_BLOCKS * BLOCK_SIZE + 1];
    int current = directory[src_slot].firstBlock;
    int read = 0;
    int size = directory[src_slot].size;
    while(read < size){
        int to_read = size - read;
        if(to_read > BLOCK_SIZE) to_read = BLOCK_SIZE;
        memcpy(&buffer[read], disk[current].data, to_read);
        read += to_read;
        current = disk[current].nextBlock;
    }
    buffer[size] = '\0';
    create_file(dst);
    write_to_file(dst, buffer);
}

void move_file(const char* src, const char* dst){
    int src_slot = -1;
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, src) == 0){
            src_slot = i;
            break;
        }
    }
    if(src_slot == -1){
        std::cout << "Error: source not found\n";
        return;
    }
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed && strcmp(directory[i].name, dst) == 0){
            std::cout << "Error: destination exists\n";
            return;
        }
    }
    strncpy(directory[src_slot].name, dst, NAME_LEN - 1);
    directory[src_slot].name[NAME_LEN - 1] = '\0';
}

void dump_fs(){
    std::cout << "\n--- Directory ---\n";
    std::cout << "Idx  Name  Size  First\n";
    for(int i = 0; i < MAX_FILES; ++i){
        if(directory[i].isUsed){
            std::cout << i << "    "
                      << directory[i].name << "    "
                      << directory[i].size << "    "
                      << directory[i].firstBlock << "\n";
        }
    }
    std::cout << "\n--- Blocks ---\n";
    for(int i = 0; i < MAX_BLOCKS; ++i){
        if(disk[i].nextBlock != -2){
            std::cout << "Block " << i
                      << " -> next=" << disk[i].nextBlock
                      << " data: ";
            for(int j = 0; j < 10 && disk[i].data[j]; ++j)
                std::cout << disk[i].data[j];
            std::cout << "\n";
        }
    }
    std::cout << "----------------\n\n";
}