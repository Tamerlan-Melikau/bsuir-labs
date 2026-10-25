#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>

template <typename T>
class Graph {
public:
    using value_type = T;
    using size_type = size_t;

    struct Edge {
        size_type targetId;
        Edge* next;
        Edge(size_type target, Edge* nextEdge = nullptr) : targetId(target), next(nextEdge) {}
    };

    struct Vertex {
        T data;
        Edge* edgesHead;
        size_type inDegree;
        Vertex(const T& value) : data(value), edgesHead(nullptr), inDegree(0) {}
    };

private:
    std::vector<Vertex> vertices;
    size_type edgesCount;

public:
    Graph() : edgesCount(0) {}

    Graph(const Graph& other) : edgesCount(other.edgesCount) {
        vertices.reserve(other.vertices.size());
        for (const auto& v : other.vertices) {
            vertices.emplace_back(v.data);
            vertices.back().inDegree = v.inDegree;
            Edge* curr = v.edgesHead;
            Edge* tail = nullptr;
            while (curr != nullptr) {
                Edge* newEdge = new Edge(curr->targetId);
                if (tail == nullptr) vertices.back().edgesHead = newEdge;
                else tail->next = newEdge;
                tail = newEdge;
                curr = curr->next;
            }
        }
    }

    ~Graph() { clear(); }

    Graph& operator=(const Graph& other) {
        if (this != &other) {
            clear();
            edgesCount = other.edgesCount;
            vertices.reserve(other.vertices.size());
            for (const auto& v : other.vertices) {
                vertices.emplace_back(v.data);
                vertices.back().inDegree = v.inDegree;
                Edge* curr = v.edgesHead;
                Edge* tail = nullptr;
                while (curr != nullptr) {
                    Edge* newEdge = new Edge(curr->targetId);
                    if (tail == nullptr) vertices.back().edgesHead = newEdge;
                    else tail->next = newEdge;
                    tail = newEdge;
                    curr = curr->next;
                }
            }
        }
        return *this;
    }

    bool empty() const { return vertices.empty(); }

    void clear() {
        for (auto& vertex : vertices) {
            Edge* current = vertex.edgesHead;
            while (current != nullptr) {
                Edge* next = current->next;
                delete current;
                current = next;
            }
        }
        vertices.clear();
        edgesCount = 0;
    }

    bool operator==(const Graph& other) const {
        if (vertices.size() != other.vertices.size() || edgesCount != other.edgesCount) return false;
        for (size_t i = 0; i < vertices.size(); ++i) {
            if (vertices[i].data != other.vertices[i].data || vertices[i].inDegree != other.vertices[i].inDegree) return false;
            Edge* e1 = vertices[i].edgesHead;
            Edge* e2 = other.vertices[i].edgesHead;
            while (e1 != nullptr && e2 != nullptr) {
                if (e1->targetId != e2->targetId) return false;
                e1 = e1->next;
                e2 = e2->next;
            }
            if (e1 != nullptr || e2 != nullptr) return false;
        }
        return true;
    }

    bool operator!=(const Graph& other) const { return !(*this == other); }
    bool operator<(const Graph& other) const { return vertices.size() < other.vertices.size(); }
    bool operator>(const Graph& other) const { return other < *this; }
    bool operator<=(const Graph& other) const { return !(*this > other); }
    bool operator>=(const Graph& other) const { return !(*this < other); }

    size_type vertexCount() const { return vertices.size(); }
    size_type edgeCount() const { return edgesCount; }
    bool hasVertex(size_type id) const { return id < vertices.size(); }

    bool hasEdge(size_type fromId, size_type toId) const {
        if (!hasVertex(fromId) || !hasVertex(toId)) return false;
        Edge* current = vertices[fromId].edgesHead;
        while (current != nullptr) {
            if (current->targetId == toId) return true;
            current = current->next;
        }
        return false;
    }

    size_type vertexDegree(size_type id) const {
        if (!hasVertex(id)) throw std::out_of_range("Vertex does not exist.");
        size_type inDeg = vertices[id].inDegree;
        size_type outDeg = 0;
        Edge* current = vertices[id].edgesHead;
        while (current != nullptr) {
            outDeg++;
            current = current->next;
        }
        return inDeg + outDeg;
    }

    size_type edgeDegree(size_type fromId, size_type toId) const {
        if (!hasEdge(fromId, toId)) throw std::out_of_range("Edge does not exist.");
        return 2;
    }

    void addVertex(const T& value) { vertices.emplace_back(value); }

    void addEdge(size_type fromId, size_type toId) {
        if (!hasVertex(fromId) || !hasVertex(toId)) throw std::out_of_range("Vertices do not exist.");
        Edge* newEdge = new Edge(toId, vertices[fromId].edgesHead);
        vertices[fromId].edgesHead = newEdge;
        edgesCount++;
        vertices[toId].inDegree++;
    }

    void removeEdge(size_type fromId, size_type toId) {
        if (!hasVertex(fromId) || !hasVertex(toId)) throw std::out_of_range("Vertex does not exist.");
        Edge* current = vertices[fromId].edgesHead;
        Edge* prev = nullptr;
        while (current != nullptr) {
            if (current->targetId == toId) {
                if (prev == nullptr) vertices[fromId].edgesHead = current->next;
                else prev->next = current->next;
                delete current;
                edgesCount--;
                vertices[toId].inDegree--;
                return;
            }
            prev = current;
            current = current->next;
        }
        throw std::out_of_range("Edge not found.");
    }

    void removeVertex(size_type id) {
        if (!hasVertex(id)) throw std::out_of_range("Vertex does not exist.");

        Edge* current = vertices[id].edgesHead;
        while (current != nullptr) {
            Edge* next = current->next;
            vertices[current->targetId].inDegree--; 
            delete current;
            current = next;
            edgesCount--;
        }
        vertices[id].edgesHead = nullptr;

        for (size_type i = 0; i < vertices.size(); ++i) {
            if (i == id) continue;
            Edge* curr = vertices[i].edgesHead;
            Edge* prev = nullptr;
            while (curr != nullptr) {
                if (curr->targetId == id) {
                    if (prev == nullptr) {
                        vertices[i].edgesHead = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    Edge* toDelete = curr;
                    curr = curr->next;
                    delete toDelete;
                    edgesCount--;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        size_type lastId = vertices.size() - 1;
        if (id != lastId) {
            std::swap(vertices[id], vertices[lastId]);
            
            for (auto& vertex : vertices) {
                Edge* curr = vertex.edgesHead;
                while (curr != nullptr) {
                    if (curr->targetId == lastId) {
                        curr->targetId = id;
                    }
                    curr = curr->next;
                }
            }
        }
        vertices.pop_back();
    }

    class VertexIterator {
    private:
        Graph* graph;
        size_type currentId;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        VertexIterator(Graph* g, size_type id) : graph(g), currentId(id) {}

        reference operator*() const { return graph->vertices[currentId].data; }
        pointer operator->() const { return &(graph->vertices[currentId].data); }

        VertexIterator& operator++() { ++currentId; return *this; }
        VertexIterator operator++(int) { VertexIterator tmp = *this; ++currentId; return tmp; }
        VertexIterator& operator--() { --currentId; return *this; }
        VertexIterator operator--(int) { VertexIterator tmp = *this; --currentId; return tmp; }

        bool operator==(const VertexIterator& other) const { return currentId == other.currentId && graph == other.graph; }
        bool operator!=(const VertexIterator& other) const { return !(*this == other); }

        size_type getId() const { return currentId; }
    };

    class EdgeIterator {
    private:
        Graph* graph;
        size_type fromId;
        Edge* currentEdge;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<size_type, size_type>;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type;

        EdgeIterator(Graph* g, size_type fId, Edge* edge) : graph(g), fromId(fId), currentEdge(edge) {}

        value_type operator*() const { return {fromId, currentEdge->targetId}; }

        EdgeIterator& operator++() {
            if (currentEdge) currentEdge = currentEdge->next;
            while (!currentEdge && fromId + 1 < graph->vertices.size()) {
                ++fromId;
                currentEdge = graph->vertices[fromId].edgesHead;
            }
            return *this;
        }
        EdgeIterator operator++(int) { EdgeIterator tmp = *this; ++(*this); return tmp; }
        
        EdgeIterator& operator--() {
            if (fromId > 0 || currentEdge != graph->vertices[fromId].edgesHead) {
                 throw std::logic_error("Reverse edge iteration not fully implemented");
            }
            return *this;
        }

        bool operator==(const EdgeIterator& other) const { return currentEdge == other.currentEdge && fromId == other.fromId; }
        bool operator!=(const EdgeIterator& other) const { return !(*this == other); }
    };

    class IncidentEdgeIterator {
    private:
        Graph* graph;
        size_type vertexId;
        Edge* currentEdge;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = size_type;
        using difference_type = std::ptrdiff_t;
        using pointer = size_type*;
        using reference = size_type;

        IncidentEdgeIterator(Graph* g, size_type vId, Edge* edge) : graph(g), vertexId(vId), currentEdge(edge) {}

        reference operator*() const { return currentEdge->targetId; }
        IncidentEdgeIterator& operator++() { if (currentEdge) currentEdge = currentEdge->next; return *this; }
        IncidentEdgeIterator operator++(int) { IncidentEdgeIterator tmp = *this; ++(*this); return tmp; }
        IncidentEdgeIterator& operator--() { throw std::logic_error("Reverse not implemented"); }

        bool operator==(const IncidentEdgeIterator& other) const { return currentEdge == other.currentEdge; }
        bool operator!=(const IncidentEdgeIterator& other) const { return !(*this == other); }
    };

    class AdjacentVertexIterator {
    private:
        Graph* graph;
        IncidentEdgeIterator edgeIt;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        AdjacentVertexIterator(Graph* g, size_type vId, Edge* edge) : graph(g), edgeIt(g, vId, edge) {}

        reference operator*() const { return graph->vertices[*edgeIt].data; }
        AdjacentVertexIterator& operator++() { ++edgeIt; return *this; }
        AdjacentVertexIterator operator++(int) { AdjacentVertexIterator tmp = *this; ++(*this); return tmp; }

        bool operator==(const AdjacentVertexIterator& other) const { return edgeIt == other.edgeIt; }
        bool operator!=(const AdjacentVertexIterator& other) const { return !(*this == other); }
    };

    VertexIterator beginVertices() { return VertexIterator(this, 0); }
    VertexIterator endVertices() { return VertexIterator(this, vertices.size()); }
    VertexIterator rbeginVertices() { return VertexIterator(this, vertices.size() - 1); }
    VertexIterator rendVertices() { return VertexIterator(this, -1); }
    VertexIterator cbeginVertices() const { return VertexIterator(const_cast<Graph*>(this), 0); }
    VertexIterator cendVertices() const { return VertexIterator(const_cast<Graph*>(this), vertices.size()); }

    EdgeIterator beginEdges() {
        size_type start = 0;
        while (start < vertices.size() && vertices[start].edgesHead == nullptr) start++;
        if (start == vertices.size()) return endEdges();
        return EdgeIterator(this, start, vertices[start].edgesHead);
    }
    EdgeIterator endEdges() { return EdgeIterator(this, vertices.size(), nullptr); }

    IncidentEdgeIterator beginIncidentEdges(size_type vertexId) {
        if (!hasVertex(vertexId)) throw std::out_of_range("Vertex does not exist.");
        return IncidentEdgeIterator(this, vertexId, vertices[vertexId].edgesHead);
    }
    IncidentEdgeIterator endIncidentEdges(size_type vertexId) {
        return IncidentEdgeIterator(this, vertexId, nullptr);
    }

    AdjacentVertexIterator beginAdjacentVertices(size_type vertexId) {
        if (!hasVertex(vertexId)) throw std::out_of_range("Vertex does not exist.");
        return AdjacentVertexIterator(this, vertexId, vertices[vertexId].edgesHead);
    }
    AdjacentVertexIterator endAdjacentVertices(size_type vertexId) {
        return AdjacentVertexIterator(this, vertexId, nullptr);
    }

    void removeVertex(VertexIterator it) { removeVertex(it.getId()); }
    void removeEdge(EdgeIterator it) {
        auto edge = *it;
        removeEdge(edge.first, edge.second);
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "Graph with " << graph.vertexCount() << " vertices and " << graph.edgeCount() << " edges:\n";
        os << "Vertices: ";
        for (size_t i = 0; i < graph.vertices.size(); ++i) {
            os << graph.vertices[i].data << " ";
        }
        os << "\nEdges: ";
        for (size_t i = 0; i < graph.vertices.size(); ++i) {
            auto* edge = graph.vertices[i].edgesHead;
            while (edge != nullptr) {
                os << "(" << graph.vertices[i].data << " -> " << graph.vertices[edge->targetId].data << ") ";
                edge = edge->next;
            }
        }
        os << "\n";
        return os;
    }
};