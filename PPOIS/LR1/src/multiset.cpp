#include "../include/multiset.hpp"

Multiset::Multiset() {

}

Multiset::Multiset(const std::string& str) {
    fromString(str);
}

void Multiset::fromString(const std::string& str) {
    
}

Multiset::Multiset(const Multiset& other){
    this->data = other.data;
}

Multiset& Multiset::operator=(const Multiset& other ){
    if (this != &other) {
        this->data = other.data;
    }
    return *this;
}

Multiset::~Multiset(){
        
}

bool Multiset::operator==(const Multiset& other) const {
    return data == other.data;
}

bool Multiset::operator!=(const Multiset& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& is, Multiset& m) {
    std::string key;
    int value;
    is >> key >> value;
    for(int i = 0; i < value; i++) {
        m.add(key);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Multiset& m) {
    os << "{ ";
    for (const auto& [element, count] : m.data) {
        if (std::holds_alternative<std::string>(element)) {
            os << std::get<std::string>(element);
        } else if (std::holds_alternative<Multiset>(element)) {
            os << std::get<Multiset>(element);
        }
        os << ": " << count << ", ";
    }
    os << "}";
    return os;
}

void Multiset::add(const std::string& element){
    data[element]++;
}

void Multiset::add(const Multiset& element){
    data[element]++;
}

void Multiset::add(const Element& element){
    data[element]++;
}

std::string Multiset::check() const {
    std::string res = "{";
    for (const auto& [element, count] : data) {
        if (std::holds_alternative<std::string>(element)) {
            res += std::get<std::string>(element);
        } else if (std::holds_alternative<Multiset>(element)) {
            res += std::get<Multiset>(element).check();
        }
        res += ":" + std::to_string(count) + ", ";
    }
    res += "}";
    return res;
}