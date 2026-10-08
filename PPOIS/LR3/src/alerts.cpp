#include "alerts.hpp"

bool Alert::isActive() {
    return true;
}

std::string Alert::getFullText() {
    return message;
}

bool AlertCriteria::matches(Weather w) {
    return enabled;
}

bool EmailNotifier::send(std::string to, std::string msg) {
    return validateEmail(to);
}

bool EmailNotifier::validateEmail(std::string email) {
    return email.find('@') != std::string::npos;
}