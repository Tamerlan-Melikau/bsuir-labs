#pragma once
#include <string>
#include <vector>
#include "weather.hpp"
#include "sensors.hpp"
#include "location.hpp"

class DataSource{
private:
    std::string name;
    TimeStamp lastUpdate;
    bool active;
public:
    Weather fetchData();
    bool isAvailable();
};

class SatelliteSource{
private:
    int ID;
    std::string name;
    double coverageArea;
public:
    void downloadImage();
    Weather processImage();
};

class WeatherStation{
private:
    std::string adress;
    Location location;
    std::vector<Sensor*> sensors;
    DataSource* source;
public:
    std::string showAdres();
    Weather readSensors();
    void calibrateAll();
};