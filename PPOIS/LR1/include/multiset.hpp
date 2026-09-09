#pragma once

#include <map>
#include <string>
#include <iostream>
#include <variant>

class Multiset;

using Element = std::variant<std::string, Multiset>;

class Multiset {
private:
    std::map<Element, int> data;
public:
    Multiset();

    Multiset(const std::string& str);
    void fromString(const std::string& str);

    Multiset(const Multiset& other);

    Multiset& operator=(const Multiset& other);

    ~Multiset();

    bool operator==(const Multiset& other) const;

    bool operator!=(const Multiset& other) const;

    friend std::istream& operator>>(std::istream& is, Multiset& m);
    friend std::ostream& operator<<(std::ostream& os, const Multiset& m);

    void add(const std::string& element);
    void add(const Multiset& element);
    void add(const Element& element);

    void remove(const std::string& element);
    void remove(const std::string& element, int count);
    void remove(const Multiset& element);

    int uniqueElementsCount() const;

    std::string check() const;

};