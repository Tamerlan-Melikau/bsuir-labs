#include "sources.hpp"

Weather DataSource::fetchData() {
    Weather w;
    return w;
}

bool DataSource::isAvailable() {
    return active;
}

void SatelliteSource::downloadImage() {
}

Weather SatelliteSource::processImage() {
    Weather w;
    return w;
}

std::string WeatherStation::showAdres() {
    return adress;
}

Weather WeatherStation::readSensors() {
    Weather w;
    return w;
}

void WeatherStation::calibrateAll() {
    for (auto* s : sensors) {
        if (s != nullptr) s->calibrate();
    }
}