#pragma once
#include <string>
#include <vector>

enum class ClimateZone{
    TROPICAL,
    ARID,
    TEMPERATE,
    CONTINENTAL,
    POLAR
};

class GeoCoordinate{
private:
    double latitude;
    double longitude;

public:
    bool isValid();
    double distanceTo(GeoCoordinate coordinate);
};

class Location{
private:
    std::string name;
    GeoCoordinate coordinate;
    std::string timezone;

public:
    std::string getLocalTime();
};

class City{
private:
    std::string name;
    int population ;
    Location location ;
public:
    int getPopulation();
    bool isCapital();
};

class Region{
private:
    std::string name;
    std::vector<City> cities ;
    enum ClimateZone climateZone;
public:
    void addCity(City);
    double getAverageTemperature();
};

class Country{
private:
    std::string name;
    std::string code;
    std::vector<Region> region;
public:
    int getRegionCount();
    Region* findRegion(std::string);
};

class Address{
private:
    std::string street;
    City city;
    int houseNumber;
public:
    std::string getFullAddress();
    bool isValid();
};