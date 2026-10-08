#pragma once
#include <string>
#include "location.hpp"
#include "weather.hpp"

enum class AlertType{
    STORM, FROST, HEAT, WIND, FLOOD
};

enum class AlertSeverity{
    INFO, WARNING, CRITICAL
};

class Alert{
private:
    std::string id;
    enum AlertType type;
    enum AlertSeverity severity;
    Location location;
    TimeStamp created;
    std::string message;
public:
    bool isActive();
    std::string getFullText();
};

class AlertCriteria{
private:
    double minTemperature;
    double maxWindSpeed;
    double minPressure;
    bool enabled;
public:
    bool matches(Weather);
};

class EmailNotifier{
private:
    std::string smtpServer;
    std::string senderEmail;
public:
    bool send(std::string, std::string);
    bool validateEmail(std::string);
};
