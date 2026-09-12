
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/multiset.hpp"
#include <sstream>

TEST_CASE("Remove nested multiset", "[multiset]") {
    Multiset m;
    Multiset inner;
    inner.add(std::string("x"));
    
    m.add(inner);
    m.add(inner);
    
    REQUIRE(m.count(inner) == 2);
    m.remove(inner);
    REQUIRE(m.count(inner) == 1);
    m.remove(inner);
    REQUIRE(m.contains(inner) == false);
}

TEST_CASE("Count and contains nested", "[multiset]") {
    Multiset m;
    Multiset inner;
    inner.add(std::string("x"));
    
    m.add(inner);
    
    REQUIRE(m.count(inner) == 1);
    REQUIRE(m.contains(inner) == true);
    
    Multiset other;
    other.add(std::string("y"));
    REQUIRE(m.count(other) == 0);
    REQUIRE(m.contains(other) == false);
}

TEST_CASE("Input operator", "[multiset]") {
    Multiset m;
    std::istringstream is("a 3");
    is >> m;
    
    REQUIRE(m.count("a") == 3);
    REQUIRE(m.size() == 3);
}

TEST_CASE("Output with nested", "[multiset]") {
    Multiset m;
    Multiset inner;
    inner.add(std::string("x"));
    m.add(inner);
    
    std::ostringstream os;
    os << m;
    REQUIRE(os.str().find("x") != std::string::npos);
}

TEST_CASE("Check with nested", "[multiset]") {
    Multiset m;
    Multiset inner;
    inner.add(std::string("x"));
    m.add(inner);
    
    std::string result = m.check();
    REQUIRE(result.find("x") != std::string::npos);
}

TEST_CASE("Parse with trailing spaces", "[multiset]") {
    Multiset m("{ a , b , c }");
    REQUIRE(m.count("a") == 1);
    REQUIRE(m.count("b") == 1);
    REQUIRE(m.count("c") == 1);
}

TEST_CASE("Empty multiset", "[multiset]") {
    Multiset m;
    REQUIRE(m.size() == 0);
    REQUIRE(m.uniqueElementsCount() == 0);
    REQUIRE(m.check() == "{}");
}

TEST_CASE("Add one element", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    REQUIRE(m.size() == 1);
    REQUIRE(m.count("a") == 1);
}

TEST_CASE("Add multiple same elements", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.add(std::string("a"));
    REQUIRE(m.size() == 3);
    REQUIRE(m.uniqueElementsCount() == 1);
    REQUIRE(m.count("a") == 3);
}

TEST_CASE("Add different elements", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.add(std::string("b"));
    m.add(std::string("c"));
    REQUIRE(m.size() == 3);
    REQUIRE(m.uniqueElementsCount() == 3);
}

TEST_CASE("Contains true", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    REQUIRE(m.contains("a") == true);
}

TEST_CASE("Contains false", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    REQUIRE(m.contains("b") == false);
}

TEST_CASE("Count missing element", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    REQUIRE(m.count("z") == 0);
}

TEST_CASE("Remove one from many", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.remove("a");
    REQUIRE(m.count("a") == 2);
    REQUIRE(m.size() == 2);
}

TEST_CASE("Remove last element", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.remove("a");
    REQUIRE(m.count("a") == 0);
    REQUIRE(m.contains("a") == false);
    REQUIRE(m.size() == 0);
}

TEST_CASE("Remove missing element", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.remove("z");
    REQUIRE(m.size() == 1);
}

TEST_CASE("Remove with count", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.remove("a", 2);
    REQUIRE(m.count("a") == 2);
}

TEST_CASE("Remove more than exists", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m.add(std::string("a"));
    m.remove("a", 5);
    REQUIRE(m.contains("a") == false);
}

TEST_CASE("Constructor from empty string", "[multiset]") {
    Multiset m("{}");
    REQUIRE(m.size() == 0);
}

TEST_CASE("Constructor from simple string", "[multiset]") {
    Multiset m("{a, a, b, c}");
    REQUIRE(m.size() == 4);
    REQUIRE(m.count("a") == 2);
    REQUIRE(m.count("b") == 1);
    REQUIRE(m.count("c") == 1);
}

TEST_CASE("Constructor with nested", "[multiset]") {
    Multiset m("{a, {b, c}, {}}");
    REQUIRE(m.size() == 3);
    REQUIRE(m.uniqueElementsCount() == 3);
    REQUIRE(m.contains("a") == true);
}

TEST_CASE("Constructor with repeated nested", "[multiset]") {
    Multiset m("{{a, b}, {a, b}, c}");
    REQUIRE(m.size() == 3);
    REQUIRE(m.uniqueElementsCount() == 2);
}

TEST_CASE("Constructor with deep nesting", "[multiset]") {
    Multiset m("{a, {b, {c, d}}}");
    REQUIRE(m.size() == 2);
    REQUIRE(m.uniqueElementsCount() == 2);
}

TEST_CASE("Constructor invalid string", "[multiset]") {
    Multiset m("abc");
    REQUIRE(m.size() == 0);
}

TEST_CASE("Constructor empty string", "[multiset]") {
    Multiset m("");
    REQUIRE(m.size() == 0);
}

TEST_CASE("Copy constructor", "[multiset]") {
    Multiset m1;
    m1.add(std::string("a"));
    m1.add(std::string("a"));
    m1.add(std::string("b"));

    Multiset m2(m1);
    REQUIRE(m1 == m2);
    REQUIRE(m2.size() == 3);
    REQUIRE(m2.count("a") == 2);
}

TEST_CASE("Assignment operator", "[multiset]") {
    Multiset m1;
    m1.add(std::string("a"));
    m1.add(std::string("b"));

    Multiset m2;
    m2.add(std::string("z"));

    m2 = m1;
    REQUIRE(m1 == m2);
    REQUIRE(m2.count("z") == 0);
}

TEST_CASE("Self assignment", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    m = m;
    REQUIRE(m.count("a") == 1);
}

TEST_CASE("Equality true", "[multiset]") {
    Multiset m1, m2;
    m1.add(std::string("a"));
    m2.add(std::string("a"));
    REQUIRE(m1 == m2);
    REQUIRE_FALSE(m1 != m2);
}

TEST_CASE("Equality false", "[multiset]") {
    Multiset m1, m2;
    m1.add(std::string("a"));
    m2.add(std::string("b"));
    REQUIRE(m1 != m2);
    REQUIRE_FALSE(m1 == m2);
}

TEST_CASE("Less than", "[multiset]") {
    Multiset m1, m2;
    m1.add(std::string("a"));
    m2.add(std::string("a"));
    m2.add(std::string("a"));
    REQUIRE(m1 < m2);
    REQUIRE(m1 <= m2);
    REQUIRE_FALSE(m1 > m2);
    REQUIRE_FALSE(m1 >= m2);
}

TEST_CASE("Greater than", "[multiset]") {
    Multiset m1, m2;
    m1.add(std::string("a"));
    m1.add(std::string("a"));
    m2.add(std::string("a"));
    REQUIRE(m1 > m2);
    REQUIRE(m1 >= m2);
    REQUIRE_FALSE(m1 < m2);
    REQUIRE_FALSE(m1 <= m2);
}

TEST_CASE("Equal comparison operators", "[multiset]") {
    Multiset m1, m2;
    m1.add(std::string("a"));
    m2.add(std::string("a"));
    REQUIRE(m1 <= m2);
    REQUIRE(m1 >= m2);
    REQUIRE_FALSE(m1 < m2);
    REQUIRE_FALSE(m1 > m2);
}

TEST_CASE("Output operator", "[multiset]") {
    Multiset m;
    m.add(std::string("a"));
    std::ostringstream os;
    os << m;
    REQUIRE(os.str().find("a") != std::string::npos);
}

TEST_CASE("Check method", "[multiset]") {
    Multiset m("{a, a, b}");
    std::string result = m.check();
    REQUIRE(result.find("a") != std::string::npos);
    REQUIRE(result.find("b") != std::string::npos);
}

TEST_CASE("Check empty", "[multiset]") {
    Multiset m;
    REQUIRE(m.check() == "{}");
}

TEST_CASE("Parse with spaces before commas", "[multiset]") {
    Multiset m("{a , b , c}");
    REQUIRE(m.count("a") == 1);
    REQUIRE(m.count("b") == 1);
    REQUIRE(m.count("c") == 1);
}