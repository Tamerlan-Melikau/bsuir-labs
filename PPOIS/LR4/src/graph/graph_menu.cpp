#include "graph/graph_menu.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include "graph/graph.h"

void runGraphMenu() {
    Graph<std::string> myGraph;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n1. Add vertex\n";
        std::cout << "2. Add edge\n";
        std::cout << "3. Print graph\n";
        std::cout << "4. Vertex count / Edge count\n";
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
            std::cout << "Error: Please enter a number\n";
            continue;
        }

        choice = std::stoi(input);

        if (choice < 0 || choice > 4) {
            std::cout << "Error: Invalid menu option\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::cout << "Enter vertex name: ";
                std::string name;
                std::cin >> name;
                myGraph.addVertex(name);
                std::cout << "Vertex '" << name << "' added\n";
                break;
            }
            case 2: {
                if (myGraph.empty()) {
                    std::cout << "Graph is empty. Add vertices first\n";
                    break;
                }
                std::cout << "Enter source vertex ID (0 to " << myGraph.vertexCount() - 1 << "): ";
                int from, to;
                std::cin >> from >> to;
                
                try {
                    myGraph.addEdge(from, to);
                    std::cout << "Edge added successfully.\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3: {
                std::cout << myGraph;
                break;
            }
            case 4: {
                std::cout << "Vertices: " << myGraph.vertexCount() << "\n";
                std::cout << "Edges: " << myGraph.edgeCount() << "\n";
                break;
            }
            case 0:
                std::cout << "Returning to main menu...\n";
                break;
        }
    }
}