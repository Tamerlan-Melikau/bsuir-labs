#include "../include/markov_algorithm.hpp"

Rule::Rule(const std::string& left, const std::string& right, bool isFinal){
    this->left = left;
    this->right = right;
    this->isFinal = isFinal;
}

std::string Rule::getLeft() const{
    return left;
}

std::string Rule::getRight() const{
    return right;
}

bool Rule::isFinalRule() const{
    return isFinal;
}

std::string Rule::toString() const{
    std::string result = left;
    result += " -> ";
    if (isFinal) {
        result += ".";
    } else {
        result += right;
    }
    
    return result;
}

MarkovAlgorithm::MarkovAlgorithm() {
}

void MarkovAlgorithm::addRule(const std::string& ruleStr) {
    size_t pos = ruleStr.find(" -> ");
    if (pos == std::string::npos) {
        return;
    }
    std::string left = ruleStr.substr(0, pos);
    std::string right = ruleStr.substr(pos + 4);
    bool isFinal = false;
    if (right == ".") {
        isFinal = true;
        right = "";
    }
    
    rules.push_back(Rule(left, right, isFinal));
}

void MarkovAlgorithm::clear() {
    rules.clear();
}

int MarkovAlgorithm::ruleCount() const {
    return rules.size();
}

std::ostream& operator<<(std::ostream& os, const MarkovAlgorithm& ma) {
    for (const Rule& r : ma.rules) {
        os << r.toString() << "\n";
    }
    return os;
}

std::string MarkovAlgorithm::apply(const std::string& input) const {
    std::string current = input;
    
    while (true) {
        bool applied = false;
        for (const Rule& r : rules) {
            size_t pos = current.find(r.getLeft());
            if (pos != std::string::npos) {
                current.replace(pos, r.getLeft().length(), r.getRight());
                applied = true;
                
                if (r.isFinalRule()) {
                    return current;
                }
                break;
            }
        }
        
        if (!applied) {
            return current;
        }
    }
}