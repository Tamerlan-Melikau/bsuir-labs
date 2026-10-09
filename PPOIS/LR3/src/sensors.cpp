#include "sensors.hpp"
#include "weather.hpp"

double Sensor::readValue(){
    return 0.0;
}

void Sensor::calibrate(){
    status = SensorStatus::ACTIVE;
}

bool Sensor::isValid(){
    return status == SensorStatus::ACTIVE;
}

double Thermometer::readTemperature(){
    return readValue();
}

double Barometer::readPressure(){
    return readValue() + altitudeCorrection;
}

double Anemometer::readWindSpeed(){
    return readValue();
}

double Anemometer::readWindDirection(){
    return readValue();
}

double Hygrometer::readHumidity(){
    return readValue();
}

void SensorNetwork::addSensor(Sensor* s){
    sensors.push_back(s);
}

void SensorNetwork::pollAll(){
    for (auto* s : sensors){
        if (s != nullptr) s->readValue();
    }
}

int SensorNetwork::getActiveSensors(){
    int count = 0;
    for (auto* s : sensors){
        if (s != nullptr && s->isValid()) count++;
    }
    return count;
}

void CalibrationTool::runCalibration() {
    calibrate();
}