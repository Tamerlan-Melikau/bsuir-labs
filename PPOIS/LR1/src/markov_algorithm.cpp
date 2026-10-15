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

Tape::Tape() = default;
Tape::Tape(const std::string& initial) : content(initial) {}
void Tape::setContent(const std::string& str) { content = str; }
const std::string& Tape::getContent() const { return content; }
void Tape::loadFromStream(std::istream& is) {
    std::getline(is, content);
}

std::ostream& operator<<(std::ostream& os, const Tape& t) {
    os << t.content;
    return os;
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

void MarkovAlgorithm::setInput(const std::string& input) {
    tape.setContent(input);
}

const std::string& MarkovAlgorithm::getTape() const {
    return tape.getContent();
}

void MarkovAlgorithm::setLogMode(bool enabled) {
    logMode = enabled;
}

bool MarkovAlgorithm::isLogMode() const {
    return logMode;
}

void MarkovAlgorithm::loadFromStream(std::istream& is) {
    std::string line;
    while (std::getline(is, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();

        if (line.empty() || line[0] == '#') continue;

        const std::string prefix = "input:";
        if (line.rfind(prefix, 0) == 0) {
            std::string value = line.substr(prefix.size());

            size_t start = value.find_first_not_of(" \t");
            size_t end   = value.find_last_not_of(" \t");
            if (start != std::string::npos) {
                value = value.substr(start, end - start + 1);
            } else {
                value = "";
            }
            tape.setContent(value);
            continue;
        }

        addRule(line);
    }
}

bool MarkovAlgorithm::step() {
    std::string current = tape.getContent();

    for (const Rule& r : rules) {
        size_t pos = current.find(r.getLeft());
        if (pos != std::string::npos) {
            current.replace(pos, r.getLeft().length(), r.getRight());
            tape.setContent(current);

            if (logMode) {
                std::cout << "Step: " << tape.getContent() << "\n";
            }

            if (r.isFinalRule()) {
                return false;
            }
            return true;
        }
    }

    return false;
}

std::string MarkovAlgorithm::apply() {
    while (step()) {
    }
    return tape.getContent();
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