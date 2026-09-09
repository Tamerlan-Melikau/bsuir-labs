#pragma once

#include <map>
#include <string>
#include <iostream>
#include <variant>

class Multiset {
private:
    std::map<Element, int> data;
public:
    Multiset();

    Multiset(const Multiset& other);
    Multiset& operator=(const Multiset& other);

    ~Multiset();

    bool operator==(const Multiset& other) const;
    bool operator!=(const Multiset& other) const;

    friend std::istream& operator>>(std::istream& is, Multiset& m);
    friend std::ostream& operator<<(std::ostream& os, const Multiset& m);

    void add(const std::string& element);
    std::string check();
};

using Element = std::variant<std::string, Multiset>;