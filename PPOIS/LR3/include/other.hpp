#pragma once
#include <string>
#include <vector>
#include "weather.hpp"
#include "sensors.hpp"
#include "people.hpp"

class Tower{
private:
    std::string id;
    Location location;
    double heightMeters;
    std::vector<Sensor*> sensors;
    TimeStamp lastMaintenance;
    WeatherStation* station;
public:
    bool needsRepair();
    int getSensorCount();
};

class MaintenanceTask{
private:
    Tower* tower;
    Master* master;
    TimeStamp scheduledDate;
    bool completed;
public:
    bool isOverdue();
};