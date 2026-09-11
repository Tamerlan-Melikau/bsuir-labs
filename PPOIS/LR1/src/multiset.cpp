#include "../include/multiset.hpp"

Multiset::Multiset() {
}

Multiset::Multiset(const std::string& str){
    fromString(str);
}

Multiset::Multiset(const Multiset& other) : data(other.data){
}

Multiset& Multiset::operator=(const Multiset& other){
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

Multiset::~Multiset(){
}

void Multiset::fromString(const std::string& str){
    if (str.size() < 2) return;
    if (str.front() != '{' || str.back() != '}') return;

    std::string content = str.substr(1, str.size() - 2);
    if (content.empty()) return;

    std::vector<std::string> elements;
    std::string current;
    int depth = 0;

    for (char c : content){
        if (c == '{'){
            depth++;
            current += c;
        } else if (c == '}'){
            depth--;
            current += c;
        } else if (c == ',' && depth == 0){
            elements.push_back(current);
            current.clear();
        } else{
            current += c;
        }
    }

    if (!current.empty()){
        elements.push_back(current);
    }

    for (std::string& elem : elements){
        while (!elem.empty() && elem.front() == ' '){
            elem.erase(0, 1);
        }
        while (!elem.empty() && elem.back() == ' '){
            elem.pop_back();
        }

        if (elem.empty()) continue;

        if (elem.front() == '{'){
            Multiset inner(elem);
            add(inner);
        } else{
            add(elem);
        }
    }
}

bool Multiset::operator==(const Multiset& other) const{
    return data == other.data;
}

bool Multiset::operator!=(const Multiset& other) const{
    return !(*this == other);
}

bool Multiset::operator<(const Multiset& other) const{
    return data < other.data;
}

bool Multiset::operator>(const Multiset& other) const{
    return other < *this;
}

bool Multiset::operator<=(const Multiset& other) const{
    return !(other < *this);
}

bool Multiset::operator>=(const Multiset& other) const{
    return !(*this < other);
}

std::istream& operator>>(std::istream& is, Multiset& m){
    std::string key;
    int value;
    is >> key >> value;
    for (int i = 0; i < value; i++){
        m.add(key);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Multiset& m){
    os << "{ ";
    for (const auto& [element, count] : m.data){
        if (std::holds_alternative<std::string>(element)){
            os << std::get<std::string>(element);
        } else if (std::holds_alternative<Multiset>(element)){
            os << std::get<Multiset>(element);
        }
        os << ": " << count << ", ";
    }
    os << "}";
    return os;
}

void Multiset::add(const Element& element){
    data[element]++;
}

void Multiset::remove(const std::string& element){
    auto it = data.find(element);
    if (it != data.end()){
        if (it->second > 1){
            it->second--;
        } else {
            data.erase(it);
        }
    }
}

void Multiset::remove(const std::string& element, int count){
    auto it = data.find(element);
    if (it != data.end()){
        if (it->second > count){
            it->second -= count;
        } else {
            data.erase(it);
        }
    }
}

void Multiset::remove(const Multiset& element){
    auto it = data.find(element);
    if (it != data.end()) {
        if (it->second > 1) {
            it->second--;
        } else {
            data.erase(it);
        }
    }
}

int Multiset::uniqueElementsCount() const{
    return data.size();
}

int Multiset::size() const{
    int total = 0;
    for (const auto& [element, cnt] : data){
        total += cnt;
    }
    return total;
}

int Multiset::count(const std::string& element) const{
    auto it = data.find(element);
    if (it != data.end()){
        return it->second;
    }
    return 0;
}

int Multiset::count(const Multiset& element) const{
    auto it = data.find(element);
    if (it != data.end()) {
        return it->second;
    }
    return 0;
}

bool Multiset::contains(const std::string& element) const{
    return data.find(element) != data.end();
}

bool Multiset::contains(const Multiset& element) const{
    return data.find(element) != data.end();
}

std::string Multiset::check() const{
    std::string res = "{";
    for (const auto& [element, count] : data){
        if (std::holds_alternative<std::string>(element)){
            res += std::get<std::string>(element);
        } else if (std::holds_alternative<Multiset>(element)){
            res += std::get<Multiset>(element).check();
        }
        res += ":" + std::to_string(count) + ", ";
    }
    res += "}";
    return res;
}