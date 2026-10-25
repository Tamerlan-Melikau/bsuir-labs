#include "cli/menu.h"
#include <iostream>
#include <cctype>
#include <string>

void runMainMenu() {
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n--- Main menu ---\n";
        std::cout << "\n1. Sorting Menu\n";
        std::cout << "2. Graph Menu\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        std::string input;
        std::cin >> input;

        bool isNumber = !input.empty();
        for (char c : input) {
            if (!std::isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            std::cout << "Error: Please enter a number\n";
            continue;
        }

        choice = std::stoi(input);

        if (choice < 0 || choice > 2) {
            std::cout << "Error: Invalid menu option. Choose from 0 to 2\n";
            continue;
        }

        switch (choice) {
            case 1:
                runSortingMenu();
                break;
            case 2:
                runGraphMenu();
                break;
            case 0:
                std::cout << "Exiting program\n";
                break;
        }
    }
}