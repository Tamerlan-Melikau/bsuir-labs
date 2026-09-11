#include "include/multiset.hpp"
#include <iostream>
#include <string>

void printMenu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Create multiset from string\n";
    std::cout << "2. Add element\n";
    std::cout << "3. Remove element\n";
    std::cout << "4. Check contains\n";
    std::cout << "5. Count element\n";
    std::cout << "6. Size\n";
    std::cout << "7. Unique count\n";
    std::cout << "8. Print multiset\n";
    std::cout << "9. Compare with another multiset\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    Multiset m;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "Enter string: ";
                std::string s;
                std::cin >> s;
                m = Multiset(s);
                std::cout << "Created!\n";
                break;
            }
            case 2: {
                std::cout << "Enter element: ";
                std::string e;
                std::cin >> e;
                m.add(e);
                std::cout << "Added!\n";
                break;
            }
            case 3: {
                std::cout << "Enter element: ";
                std::string e;
                std::cin >> e;
                m.remove(e);
                std::cout << "Removed!\n";
                break;
            }
            case 4: {
                std::cout << "Enter element: ";
                std::string e;
                std::cin >> e;
                std::cout << (m.contains(e) ? "Yes" : "No") << "\n";
                break;
            }
            case 5: {
                std::cout << "Enter element: ";
                std::string e;
                std::cin >> e;
                std::cout << "Count: " << m.count(e) << "\n";
                break;
            }
            case 6:
                std::cout << "Size: " << m.size() << "\n";
                break;
            case 7:
                std::cout << "Unique: " << m.uniqueElementsCount() << "\n";
                break;
            case 8:
                std::cout << m << "\n";
                break;
            case 9: {
                std::cout << "Enter string for second multiset: ";
                std::string s;
                std::cin >> s;
                Multiset other(s);

                std::cout << "m == other: " << (m == other) << "\n";
                std::cout << "m != other: " << (m != other) << "\n";
                std::cout << "m <  other: " << (m < other) << "\n";
                std::cout << "m >  other: " << (m > other) << "\n";
                std::cout << "m <= other: " << (m <= other) << "\n";
                std::cout << "m >= other: " << (m >= other) << "\n";
                break;
            }
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}