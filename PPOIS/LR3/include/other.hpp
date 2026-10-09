#pragma once
#include <string>
#include <vector>
#include "weather.hpp"
#include "sensors.hpp"
#include "people.hpp"

class Tower {
private:
    std::string id = "";
    Location location;
    double heightMeters = 0.0;
    std::vector<Sensor*> sensors;
    TimeStamp lastMaintenance;
    WeatherStation* station = nullptr;
public:
    bool needsRepair();
    int getSensorCount();
};

class MaintenanceTask {
private:
    Tower* tower = nullptr;
    Master* master = nullptr;
    TimeStamp scheduledDate;
    bool completed = false;
public:
    bool isOverdue();
};