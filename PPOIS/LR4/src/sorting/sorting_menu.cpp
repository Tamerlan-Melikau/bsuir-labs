#include "sorting/sorting_menu.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "car/car.h"
#include "sorting/quicksort.h"
#include "sorting/sorting_network.h"

void runSortingMenu() {
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n1. Sort numbers (Quicksort)\n";
        std::cout << "2. Sort cars by year (Quicksort)\n";
        std::cout << "3. Sort numbers (Sorting Network)\n";
        std::cout << "4. Sort cars by year (Sorting Network)\n";
        std::cout << "0. Back to main menu\n";
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
            std::cout << "Error: Please enter a NUMBER\n";
            continue;
        }

        choice = std::stoi(input);

        if (choice < 0 || choice > 4) {
            std::cout << "Error: Invalid menu option. Choose from 0 to 4\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::vector<int> numbers = {10, 1, 5, 3, 8, 2};
                std::cout << "Before: ";
                for (int n : numbers) std::cout << n << " ";
                std::cout << "\n";
                quickSort(numbers, std::less<int>());
                std::cout << "After:  ";
                for (int n : numbers) std::cout << n << " ";
                std::cout << "\n";
                break;
            }
            case 2: {
                std::vector<Car> cars = {
                    Car("Toyota", 2015, 120000),
                    Car("BMW", 2020, 50000),
                    Car("Audi", 2018, 80000)
                };
                std::cout << "Before:\n";
                for (const auto& c : cars) std::cout << c.toString() << "\n";
                quickSort(cars, CarByYear());
                std::cout << "After:\n";
                for (const auto& c : cars) std::cout << c.toString() << "\n";
                break;
            }
            case 3: {
                std::vector<int> numbers = {8, 2, 10, 1};
                std::cout << "Before: ";
                for (int n : numbers) std::cout << n << " ";
                std::cout << "\n";
                sortingNetwork4(numbers, std::less<int>());
                std::cout << "After:  ";
                for (int n : numbers) std::cout << n << " ";
                std::cout << "\n";
                break;
            }
            case 4: {
                std::vector<Car> cars = {
                    Car("Lada", 2010, 200000),
                    Car("Ford", 2019, 90000),
                    Car("Kia", 2015, 150000),
                    Car("Tesla", 2022, 10000)
                };
                std::cout << "Before:\n";
                for (const auto& c : cars) std::cout << c.toString() << "\n";
                sortingNetwork4(cars, CarByYear());
                std::cout << "After:\n";
                for (const auto& c : cars) std::cout << c.toString() << "\n";
                break;
            }
            case 0:
                std::cout << "Returning to main menu...\n";
                break;
        }
    }
}