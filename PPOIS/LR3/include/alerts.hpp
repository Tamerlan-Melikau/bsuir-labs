#pragma once
#include <string>
#include "location.hpp"
#include "weather.hpp"

enum class AlertType {
    STORM, FROST, HEAT, WIND, FLOOD
};

enum class AlertSeverity {
    INFO, WARNING, CRITICAL
};

class Alert {
private:
    std::string id = "";
    AlertType type = AlertType::STORM;
    AlertSeverity severity = AlertSeverity::INFO;
    Location location;
    TimeStamp created;
    std::string message = "";
public:
    bool isActive();
    std::string getFullText();
};

class AlertCriteria {
private:
    double minTemperature = 0.0;
    double maxWindSpeed = 0.0;
    double minPressure = 0.0;
    bool enabled = false;
public:
    bool matches(Weather);
};

class EmailNotifier {
private:
    std::string smtpServer = "";
    std::string senderEmail = "";
public:
    bool send(std::string, std::string);
    bool validateEmail(std::string);
};