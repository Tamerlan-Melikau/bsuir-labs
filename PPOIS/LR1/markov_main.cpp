#include "include/markov_algorithm.hpp"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "\n=== MARKOV MENU ===\n";
    std::cout << "1. Add rule\n";
    std::cout << "2. Clear rules\n";
    std::cout << "3. Show rules\n";
    std::cout << "4. Apply algorithm\n";
    std::cout << "5. Rule count\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    MarkovAlgorithm ma;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        if (choice == 0) break;
        
        switch (choice) {
            case 1: {
                std::cout << "Enter rule (e.g. 'ab -> c'): ";
                std::string rule;
                std::cin.ignore();
                std::getline(std::cin, rule);
                ma.addRule(rule);
                std::cout << "Rule added!\n";
                break;
            }
            case 2:
                ma.clear();
                std::cout << "Cleared!\n";
                break;
            case 3:
                std::cout << "Rules:\n" << ma;
                break;
            case 4: {
                std::cout << "Enter input string: ";
                std::string input;
                std::cin >> input;
                std::cout << "Result: " << ma.apply(input) << "\n";
                break;
            }
            case 5:
                std::cout << "Rule count: " << ma.ruleCount() << "\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    }
    
    return 0;
}

// g++ -std=c++17 markov_main.cpp src/markov_algorithm.cpp -o markov
// ./markov