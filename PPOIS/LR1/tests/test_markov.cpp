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

TEST_CASE("Tape default constructor", "[markov][tape]") {
    Tape t;
    REQUIRE(t.getContent() == "");
}

TEST_CASE("Tape constructor from string", "[markov][tape]") {
    Tape t("hello");
    REQUIRE(t.getContent() == "hello");
}

TEST_CASE("Tape setContent", "[markov][tape]") {
    Tape t;
    t.setContent("abc");
    REQUIRE(t.getContent() == "abc");
}

TEST_CASE("Tape output operator", "[markov][tape]") {
    Tape t("xyz");
    std::ostringstream os;
    os << t;
    REQUIRE(os.str() == "xyz");
}

TEST_CASE("Tape loadFromStream", "[markov][tape]") {
    std::istringstream is("loaded_line\n");
    Tape t;
    t.loadFromStream(is);
    REQUIRE(t.getContent() == "loaded_line");
}

TEST_CASE("setInput / getTape", "[markov]") {
    MarkovAlgorithm ma;
    ma.setInput("abc");
    REQUIRE(ma.getTape() == "abc");
}

TEST_CASE("setLogMode / isLogMode", "[markov]") {
    MarkovAlgorithm ma;
    REQUIRE(ma.isLogMode() == false);
    ma.setLogMode(true);
    REQUIRE(ma.isLogMode() == true);
    ma.setLogMode(false);
    REQUIRE(ma.isLogMode() == false);
}

TEST_CASE("step applies one rule", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.setInput("a");
    bool cont = ma.step();
    REQUIRE(cont == true);
    REQUIRE(ma.getTape() == "b");
}

TEST_CASE("step returns false when no rule matches", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.setInput("xyz");
    bool cont = ma.step();
    REQUIRE(cont == false);
    REQUIRE(ma.getTape() == "xyz");
}

TEST_CASE("step stops on final rule", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("ab -> c");
    ma.addRule("c -> .");
    ma.setInput("ab");
    REQUIRE(ma.step() == true);
    REQUIRE(ma.getTape() == "c");
    REQUIRE(ma.step() == false);
    REQUIRE(ma.getTape() == "");
}

TEST_CASE("apply() without args uses internal tape", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("a -> b");
    ma.addRule("b -> c");
    ma.setInput("a");
    REQUIRE(ma.apply() == "c");
    REQUIRE(ma.getTape() == "c");
}

TEST_CASE("apply() with final rule", "[markov]") {
    MarkovAlgorithm ma;
    ma.addRule("ab -> c");
    ma.addRule("c -> .");
    ma.setInput("ab");
    REQUIRE(ma.apply() == "");
}

TEST_CASE("loadFromStream reads input and rules", "[markov]") {
    std::istringstream is(
        "# comment\n"
        "input: abcca\n"
        "\n"
        "bc -> e\n"
        "ec -> d\n"
        "ad -> a\n"
        "aa -> X\n"
    );
    MarkovAlgorithm ma;
    ma.loadFromStream(is);
    REQUIRE(ma.getTape() == "abcca");
    REQUIRE(ma.ruleCount() == 4);
}

TEST_CASE("loadFromStream skips comments and empty lines", "[markov]") {
    std::istringstream is(
        "# header\n"
        "\n"
        "a -> b\n"
        "# another comment\n"
        "b -> .\n"
    );
    MarkovAlgorithm ma;
    ma.loadFromStream(is);
    REQUIRE(ma.ruleCount() == 2);
    REQUIRE(ma.getTape() == "");
}

TEST_CASE("loadFromStream full pipeline", "[markov]") {
    std::istringstream is(
        "input: abcca\n"
        "bc -> e\n"
        "ec -> d\n"
        "ad -> a\n"
        "aa -> X\n"
    );
    MarkovAlgorithm ma;
    ma.loadFromStream(is);
    REQUIRE(ma.apply() == "X");
}