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
        std::cout << "5. Calculate Degree (Vertex or Edge)\n";
        std::cout << "6. Remove vertex\n";
        std::cout << "7. Remove edge\n";
        std::cout << "8. Show all edges\n";
        std::cout << "9. Show all vertices\n";
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

        if (choice < 0 || choice > 9) {
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
            case 5: {
                std::cout << "What degree to calculate?\n";
                std::cout << "1. Vertex\n";
                std::cout << "2. Edge\n";
                std::cout << "Enter choice: ";
                int subChoice;
                std::cin >> subChoice;

                if (subChoice == 1) {
                    std::cout << "Enter vertex ID: ";
                    int id;
                    std::cin >> id;
                    try {
                        std::cout << "Vertex degree: " << myGraph.vertexDegree(id) << "\n";
                    } catch (const std::exception& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                } else if (subChoice == 2) {
                    std::cout << "Enter source ID and target ID: ";
                    int from, to;
                    std::cin >> from >> to;
                    try {
                        std::cout << "Edge degree: " << myGraph.edgeDegree(from, to) << "\n";
                    } catch (const std::exception& e) {
                        std::cout << "Error: " << e.what() << "\n";
                    }
                } else {
                    std::cout << "Invalid choice\n";
                }
                break;
            }
            case 6: {
                std::cout << "Enter vertex ID to remove: ";
                int id;
                std::cin >> id;
                try {
                    myGraph.removeVertex(id);
                    std::cout << "Vertex removed successfully.\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 7: {
                std::cout << "Enter source ID and target ID: ";
                int from, to;
                std::cin >> from >> to;
                try {
                    myGraph.removeEdge(from, to);
                    std::cout << "Edge removed successfully.\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 8: {
                std::cout << "\n--- ALL EDGES (using EdgeIterator) ---\n";
                if (myGraph.edgeCount() == 0) {
                    std::cout << "No edges in graph.\n";
                    break;
                }

                std::cout << "Forward traversal (++):\n";
                for (auto it = myGraph.beginEdges(); it != myGraph.endEdges(); ++it) {
                    auto edge = *it;
                    std::cout << "  Edge: " << edge.first << " -> " << edge.second << "\n";
                }

                std::cout << "\nReverse traversal (--):\n";
                auto first = myGraph.beginEdges();
                auto it = myGraph.endEdges();
                while (it != first) {
                    --it;
                    auto edge = *it;
                    std::cout << "  Edge: " << edge.first << " -> " << edge.second << "\n";
                }
                break;
            }

            case 9: {
                std::cout << "\n--- ALL VERTICES (using VertexIterator) ---\n";
                if (myGraph.empty()) {
                    std::cout << "Graph is empty.\n";
                    break;
                }

                std::cout << "Forward traversal (++):\n";
                int index = 0;
                for (auto it = myGraph.beginVertices(); it != myGraph.endVertices(); ++it) {
                    std::cout << "  ID " << index << ": " << *it << "\n";
                    index++;
                }

                std::cout << "\nReverse traversal (--):\n";
                for (auto it = myGraph.rbeginVertices(); it != myGraph.rendVertices(); --it) {
                    std::cout << "  " << *it << "\n";
                }
                break;
            }


            case 0:
                std::cout << "Returning to main menu...\n";
                break;
        }
    }
}