#include "include/markov_algorithm.hpp"
#include <iostream>
#include <fstream>
#include <string>

static void printUsage(const char* prog) {
    std::cout << "Usage: " << prog << " <file> [-log]\n"
              << "  <file>  File with the feed state and rules\n"
              << "  -log    Show feed state after each rule\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string filename = argv[1];
    bool log = false;
    for (int i = 2; i < argc; ++i) {
        if (std::string(argv[i]) == "-log") log = true;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << "\n";
        return 1;
    }

    MarkovAlgorithm ma;
    ma.setLogMode(log);

    ma.loadFromStream(file);

    std::cout << "Initial tape: " << ma.getTape() << "\n";
    std::string result = ma.apply();
    std::cout << "Result: " << result << "\n";

    return 0;
}