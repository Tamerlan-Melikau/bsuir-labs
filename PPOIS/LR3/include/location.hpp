#pragma once
#include <string>
#include <vector>

enum class ClimateZone {
    TROPICAL,
    ARID,
    TEMPERATE,
    CONTINENTAL,
    POLAR
};

class GeoCoordinate {
private:
    double latitude = 0.0;
    double longitude = 0.0;
public:
    bool isValid();
    double distanceTo(GeoCoordinate coordinate);
};

class Location {
private:
    std::string name = "";
    GeoCoordinate coordinate;
    std::string timezone = "";
public:
    std::string getLocalTime();
    std::string getName();
};

class City {
private:
    std::string name = "";
    int population = 0;
    Location location;
public:
    int getPopulation();
    bool isCapital();
};

class Region {
private:
    std::string name = "";
    std::vector<City> cities;
    ClimateZone climateZone = ClimateZone::TEMPERATE;
public:
    void addCity(City);
    double getAverageTemperature();
    std::string getName();
};

class Country {
private:
    std::string name = "";
    std::string code = "";
    std::vector<Region> region;
public:
    int getRegionCount();
    Region* findRegion(std::string);
};

class Address {
private:
    std::string street = "";
    City city;
    int houseNumber = 0;
public:
    std::string getFullAddress();
    bool isValid();
};