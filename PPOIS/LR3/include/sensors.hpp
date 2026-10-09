#pragma once
#include <string>
#include <vector>

class TimeStamp;

enum class SensorStatus {
    ACTIVE,
    BROKEN,
    CALIBRATING
};

enum class HygrometerType {
    CAPACITIVE,
    RESISTIVE,
};

enum class TempUnit {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

class Sensor {
private:
    std::string id = "";
    SensorStatus status = SensorStatus::CALIBRATING;
    double accuracy = 1.0;
    TimeStamp* lastCalibration = nullptr;
public:
    double readValue();
    void calibrate();
    bool isValid();
};

class Thermometer : public Sensor {
private:
    TempUnit unit = TempUnit::CELSIUS;
public:
    double readTemperature();
};

class Barometer : public Sensor {
private:
    double altitudeCorrection = 0.0;
public:
    double readPressure();
};

class Anemometer : public Sensor {
private:
    double maxSpeed = 0.0;
public:
    double readWindSpeed();
    double readWindDirection();
};

class Hygrometer : public Sensor {
private:
    HygrometerType type = HygrometerType::CAPACITIVE;
public:
    double readHumidity();
};

class SensorNetwork {
private:
    std::vector<Sensor*> sensors;
    std::string location = "";
public:
    void addSensor(Sensor*);
    void pollAll();
    int getActiveSensors();
};

class CalibrationTool : private Sensor {
public:
    void runCalibration();
};