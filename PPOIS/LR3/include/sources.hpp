#pragma once
#include <string>
#include <vector>
#include "weather.hpp"
#include "sensors.hpp"
#include "location.hpp"

class DataSource {
private:
    std::string name = "";
    TimeStamp lastUpdate;
    bool active = false;
public:
    Weather fetchData();
    bool isAvailable();
};

class SatelliteSource {
private:
    int ID = 0;
    std::string name = "";
    double coverageArea = 0.0;
public:
    void downloadImage();
    Weather processImage();
};

class WeatherStation {
private:
    std::string adress = "";
    Location location;
    std::vector<Sensor*> sensors;
    DataSource* source = nullptr;
public:
    std::string showAdres();
    Weather readSensors();
    void calibrateAll();
};