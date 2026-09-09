#include "../include/multiset.hpp"

Multiset::Multiset() {

}

Multiset::Multiset(const Multiset& other){
    this->data = other.data;
}

Multiset& Multiset::operator=(const Multiset& other ){
    data = other.data;
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

std::ostream& operator<<(std::ostream& os, const Multiset& m) {
    os << "{ ";
    for (const auto& pair : m.data) {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}


void Multiset::add(const std::string& element){
    data[element]++;
}

std::string Multiset::check(){
    std::string res = "{";
    for(auto pair: data){
        res += pair.first;
        res += ":";
        res += std::to_string(pair.second);
        res += ", ";
    }
    res += "}";
    return res;
}