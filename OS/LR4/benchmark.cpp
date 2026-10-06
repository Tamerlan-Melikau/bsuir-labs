#include "fs.h"
#include <chrono>

using namespace std::chrono;

long measure_write(int blocks, int reps){
    int bytes = blocks * BLOCK_SIZE;
    char* data = new char[bytes + 1];
    for(int i = 0; i < bytes; ++i) data[i] = 'A';
    data[bytes] = '\0';

    auto t1 = high_resolution_clock::now();
    for(int r = 0; r < reps; ++r){
        init_fs();
        create_file("test");
        write_to_file("test", data);
    }
    auto t2 = high_resolution_clock::now();

    delete[] data;
    return duration_cast<microseconds>(t2 - t1).count() / reps;
}

long measure_read(int blocks, int reps){
    int bytes = blocks * BLOCK_SIZE;
    char* data = new char[bytes + 1];
    for(int i = 0; i < bytes; ++i) data[i] = 'A';
    data[bytes] = '\0';

    init_fs();
    create_file("test");
    write_to_file("test", data);

    volatile int sink = 0;
    auto t1 = high_resolution_clock::now();
    for(int r = 0; r < reps; ++r){
        int current = directory[0].firstBlock;
        int read = 0;
        while(read < directory[0].size){
            int to_read = directory[0].size - read;
            if(to_read > BLOCK_SIZE) to_read = BLOCK_SIZE;
            for(int i = 0; i < to_read; ++i) sink += disk[current].data[i];
            read += to_read;
            current = disk[current].nextBlock;
        }
    }
    auto t2 = high_resolution_clock::now();

    delete[] data;
    return duration_cast<microseconds>(t2 - t1).count() / reps;
}

int main(){
    const int REPS = 100;

    std::cout << "--- WRITE ---\n";
    std::cout << "Blocks\tBytes\tTime(us)\tUs/block\n";
    for(int b = 10; b <= 90; b += 10){
        long us = measure_write(b, REPS);
        std::cout << b << "\t" << b * BLOCK_SIZE << "\t" << us << "\t\t"
                  << (double)us / b << "\n";
    }

    std::cout << "\n--- READ ---\n";
    std::cout << "Blocks\tBytes\tTime(us)\tUs/block\n";
    for(int b = 10; b <= 90; b += 10){
        long us = measure_read(b, REPS);
        std::cout << b << "\t" << b * BLOCK_SIZE << "\t" << us << "\t\t"
                  << (double)us / b << "\n";
    }

    return 0;
}