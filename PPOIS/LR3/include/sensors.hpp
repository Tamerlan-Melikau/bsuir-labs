#pragma once
#include <string>
#include <vector>

class TimeStamp;

enum class SensorStatus{
    ACTIVE,
    BROKEN,
    CALIBRATING
};

enum class HygrometerType{
    CAPACITIVE,
    RESISTIVE,
};

enum class TempUnit{
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

class Sensor{
private:
    std::string id;
    enum SensorStatus status;
    double accuracy;
    TimeStamp* lastCalibration;
public:
    double readValue();
    void calibrate();
    bool isValid();
};

class Thermometer:public Sensor{
private:
    enum TempUnit unit;
public:
    double readTemperature();
};

class Barometer:public Sensor{
private:
    double altitudeCorrection ;
public:
    double readPressure();
};

class Anemometer:public Sensor{
private:
    double maxSpeed;
public:
    double readWindSpeed();
    double readWindDirection();
};

class Hygrometer:public Sensor{
private:
    enum HygrometerType type;
public:
    double readHumidity();
};

class SensorNetwork{
private:
    std::vector<Sensor*> sensors;
    std::string location;
public:
    void addSensor(Sensor*);
    void pollAll();
    int getActiveSensors();
};