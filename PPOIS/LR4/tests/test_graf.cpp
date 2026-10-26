#include <gtest/gtest.h>
#include "graph/graph.h"
#include <string>
#include <vector>

TEST(GraphTest, DefaultConstructor) {
    Graph<int> g;
    EXPECT_TRUE(g.empty());
    EXPECT_EQ(g.vertexCount(), 0u);
    EXPECT_EQ(g.edgeCount(), 0u);
}

TEST(GraphTest, AddVertex) {
    Graph<int> g;
    g.addVertex(10);
    EXPECT_FALSE(g.empty());
    EXPECT_EQ(g.vertexCount(), 1u);
    EXPECT_TRUE(g.hasVertex(0));
    EXPECT_FALSE(g.hasVertex(1));
}

TEST(GraphTest, AddEdge) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addEdge(0, 1);
    
    EXPECT_TRUE(g.hasEdge(0, 1));
    EXPECT_FALSE(g.hasEdge(1, 0));
    EXPECT_EQ(g.edgeCount(), 1u);
}

TEST(GraphTest, AddEdgeThrowsOnInvalidVertex) {
    Graph<int> g;
    g.addVertex(10);
    EXPECT_THROW(g.addEdge(0, 1), std::out_of_range);
}

TEST(GraphTest, VertexDegree) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    
    EXPECT_EQ(g.vertexDegree(0), 2u);
    EXPECT_EQ(g.vertexDegree(1), 2u);
    EXPECT_EQ(g.vertexDegree(2), 2u);
}

TEST(GraphTest, RemoveEdge) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addEdge(0, 1);
    EXPECT_TRUE(g.hasEdge(0, 1));
    
    g.removeEdge(0, 1);
    EXPECT_FALSE(g.hasEdge(0, 1));
    EXPECT_EQ(g.edgeCount(), 0u);
}

TEST(GraphTest, RemoveVertex) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    
    g.removeVertex(1);
    EXPECT_EQ(g.vertexCount(), 2u);
    EXPECT_EQ(g.edgeCount(), 1u);
    EXPECT_TRUE(g.hasEdge(1, 0));
}

TEST(GraphTest, Clear) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addEdge(0, 1);
    
    g.clear();
    EXPECT_TRUE(g.empty());
    EXPECT_EQ(g.vertexCount(), 0u);
    EXPECT_EQ(g.edgeCount(), 0u);
}

TEST(GraphTest, CopyConstructorAndAssignment) {
    Graph<int> g1;
    g1.addVertex(10);
    g1.addVertex(20);
    g1.addEdge(0, 1);
    
    Graph<int> g2(g1);
    EXPECT_EQ(g1, g2);
    
    Graph<int> g3;
    g3 = g1;
    EXPECT_EQ(g1, g3);
}

TEST(GraphTest, ComparisonOperators) {
    Graph<int> g1;
    g1.addVertex(10);
    
    Graph<int> g2;
    g2.addVertex(10);
    g2.addVertex(20);
    
    EXPECT_TRUE(g1 != g2);
    EXPECT_TRUE(g1 < g2);
    EXPECT_TRUE(g2 > g1);
    EXPECT_TRUE(g1 <= g2);
    EXPECT_TRUE(g2 >= g1);
}

TEST(GraphIteratorTest, VertexIterator) {
    Graph<std::string> g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    
    std::vector<std::string> result;
    for (auto it = g.beginVertices(); it != g.endVertices(); ++it) {
        result.push_back(*it);
    }
    
    ASSERT_EQ(result.size(), 3u);
    EXPECT_EQ(result[0], "A");
    EXPECT_EQ(result[1], "B");
    EXPECT_EQ(result[2], "C");
}

TEST(GraphIteratorTest, ReverseVertexIterator) {
    Graph<std::string> g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    std::vector<std::string> result;
    for (auto it = g.rbeginVertices(); it != g.rendVertices(); --it) {
        result.push_back(*it);
    }

    ASSERT_EQ(result.size(), 3u);
    EXPECT_EQ(result[0], "C");
    EXPECT_EQ(result[1], "B");
    EXPECT_EQ(result[2], "A");
}

TEST(GraphIteratorTest, EdgeIterator) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 0);

    std::vector<std::pair<size_t, size_t>> result;
    for (auto it = g.beginEdges(); it != g.endEdges(); ++it) {
        result.push_back(*it);
    }

    ASSERT_EQ(result.size(), 3u);
    EXPECT_EQ(result[0].first, 0u);
    EXPECT_EQ(result[0].second, 2u);
    EXPECT_EQ(result[1].first, 0u);
    EXPECT_EQ(result[1].second, 1u);
    EXPECT_EQ(result[2].first, 2u);
    EXPECT_EQ(result[2].second, 0u);
}

TEST(GraphIteratorTest, ReverseEdgeIterator) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 0);

    std::vector<std::pair<size_t, size_t>> result;
    auto first = g.beginEdges();
    auto it = g.endEdges();
    while (it != first) {
        --it;
        result.push_back(*it);
    }

    ASSERT_EQ(result.size(), 3u);
    EXPECT_EQ(result[0].first, 2u);
    EXPECT_EQ(result[0].second, 0u);
    EXPECT_EQ(result[1].first, 0u);
    EXPECT_EQ(result[1].second, 1u);
    EXPECT_EQ(result[2].first, 0u);
    EXPECT_EQ(result[2].second, 2u);
}

TEST(GraphIteratorTest, RemoveVertexByIterator) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    
    auto it = g.beginVertices();
    g.removeVertex(it);
    
    EXPECT_EQ(g.vertexCount(), 1u);
}

TEST(GraphTest, OutputOperator) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addEdge(0, 1);
    
    std::ostringstream oss;
    oss << g;
    std::string output = oss.str();
    
    EXPECT_NE(output.find("2 vertices"), std::string::npos);
    EXPECT_NE(output.find("1 edges"), std::string::npos);
    EXPECT_NE(output.find("10"), std::string::npos);
    EXPECT_NE(output.find("20"), std::string::npos);
}

TEST(GraphTest, EdgeDegreeThrows) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    EXPECT_THROW(g.edgeDegree(0, 1), std::out_of_range);
}

TEST(GraphTest, RemoveVertexThrows) {
    Graph<int> g;
    EXPECT_THROW(g.removeVertex(5), std::out_of_range);
}

TEST(GraphTest, RemoveEdgeThrows) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    EXPECT_THROW(g.removeEdge(0, 1), std::out_of_range);
}

TEST(GraphTest, AddDuplicateEdgeThrows) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addEdge(0, 1);
    
    EXPECT_THROW(g.addEdge(0, 1), std::invalid_argument);
    
    EXPECT_EQ(g.edgeCount(), 1u);
}

TEST(GraphTest, EdgeDegreeForLoop) {
    Graph<int> g;
    g.addVertex(10);
    g.addEdge(0, 0);
    EXPECT_EQ(g.edgeDegree(0, 0), 1u);
}

TEST(GraphIteratorTest, AdjacentVertexIterator) {
    Graph<int> g;
    g.addVertex(10);
    g.addVertex(20);
    g.addVertex(30);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    std::vector<int> result;
    for (auto it = g.beginAdjacentVertices(0); it != g.endAdjacentVertices(0); ++it) {
        result.push_back(*it);
    }

    ASSERT_EQ(result.size(), 2u);
    EXPECT_EQ(result[0], 30);
    EXPECT_EQ(result[1], 20);
}