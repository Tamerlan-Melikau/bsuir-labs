#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/markov_algorithm.hpp"
#include <sstream>

TEST_CASE("Rule constructor", "[markov]") {
    Rule r("ab", "c", false);
    REQUIRE(r.getLeft() == "ab");
    REQUIRE(r.getRight() == "c");
    REQUIRE(r.isFinalRule() == false);
}

TEST_CASE("Rule constructor final", "[markov]") {
    Rule r("bc", "", true);
    REQUIRE(r.getLeft() == "bc");
    REQUIRE(r.getRight() == "");
    REQUIRE(r.isFinalRule() == true);
}

TEST_CASE("Rule getters", "[markov]") {
    Rule r("hello", "world", false);
    REQUIRE(r.getLeft() == "hello");
    REQUIRE(r.getRight() == "world");
}

TEST_CASE("Rule isFinalRule", "[markov]") {
    Rule r1("x", "", true);
    Rule r2("x", "y", false);
    REQUIRE(r1.isFinalRule() == true);
    REQUIRE(r2.isFinalRule() == false);
}

TEST_CASE("Rule toString", "[markov]") {
    Rule r1("ab", "c", false);
    Rule r2("bc", "", true);
    REQUIRE(r1.toString() == "ab -> c");
    REQUIRE(r2.toString() == "bc -> .");
}

TEST_CASE("addRule normal", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("ab -> c");
    REQUIRE(ma.ruleCount() == 1);
}

TEST_CASE("addRule final", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("bc -> .");
    REQUIRE(ma.ruleCount() == 1);
}

TEST_CASE("addRule invalid", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("abc");
    ma.addRule("");
    REQUIRE(ma.ruleCount() == 0);
}

TEST_CASE("addRule multiple", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.addRule("b -> c");
    ma.addRule("c -> .");
    REQUIRE(ma.ruleCount() == 3);
}

TEST_CASE("ruleCount", "[markov]") {
    MarkovAlgorithm ma;
    REQUIRE(ma.ruleCount() == 0);
    ma.addRule("a -> b");
    ma.addRule("b -> c");
    REQUIRE(ma.ruleCount() == 2);
}

TEST_CASE("clear", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.addRule("b -> c");
    ma.clear();
    REQUIRE(ma.ruleCount() == 0);
}

TEST_CASE("apply simple", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    REQUIRE(ma.apply("a") == "b");
}

TEST_CASE("apply no match", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    REQUIRE(ma.apply("xyz") == "xyz");
}

TEST_CASE("apply empty input", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    REQUIRE(ma.apply("") == "");
}

TEST_CASE("apply chain", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.addRule("b -> c");
    REQUIRE(ma.apply("a") == "c");
}

TEST_CASE("apply final", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("ab -> c");
    ma.addRule("c -> .");
    REQUIRE(ma.apply("ab") == "");
}

TEST_CASE("apply substring", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("bc -> e");
    REQUIRE(ma.apply("abcc") == "aec");
}

TEST_CASE("apply multiple occurrences", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("aa -> b");
    REQUIRE(ma.apply("aaaa") == "bb");
}

TEST_CASE("apply chain bc-ec-ad", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("bc -> e");
    ma.addRule("ec -> d");
    ma.addRule("ad -> a");
    ma.addRule("aa -> X");
    REQUIRE(ma.apply("abcca") == "X");
}

TEST_CASE("output multiple rules", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.addRule("c -> .");
    std::ostringstream os;
    os << ma;
    std::string result = os.str();
    REQUIRE(result.find("a -> b") != std::string::npos);
    REQUIRE(result.find("c -> .") != std::string::npos);
}