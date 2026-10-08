#include "location.hpp"
#include <cmath>

bool GeoCoordinate::isValid() {
    return latitude >= -90.0 && latitude <= 90.0 &&
           longitude >= -180.0 && longitude <= 180.0;
}

double GeoCoordinate::distanceTo(GeoCoordinate coordinate) {
    double dLat = (coordinate.latitude - latitude) * M_PI / 180.0;
    double dLon = (coordinate.longitude - longitude) * M_PI / 180.0;
    double a = std::sin(dLat/2) * std::sin(dLat/2) +
               std::cos(latitude * M_PI / 180.0) *
               std::cos(coordinate.latitude * M_PI / 180.0) *
               std::sin(dLon/2) * std::sin(dLon/2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));
    return 6371.0 * c;
}

std::string Location::getLocalTime() {
    return name;
}

int City::getPopulation() {
    return population;
}

bool City::isCapital() {
    return population > 1000000;
}

void Region::addCity(City c) {
    cities.push_back(c);
}

double Region::getAverageTemperature() {
    return 0.0;
}

int Country::getRegionCount() {
    return region.size();
}

Region* Country::findRegion(std::string n) {
    for (auto& r : region) {
        if (r.name == n) return &r;
    }
    return nullptr;
}

std::string Address::getFullAddress() {
    return street + " " + std::to_string(houseNumber);
}

bool Address::isValid() {
    return !street.empty() && houseNumber > 0;
}