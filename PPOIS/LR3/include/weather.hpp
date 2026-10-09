#pragma once
#include <string>
#include "location.hpp"
#include "sensors.hpp"

class Temperature {
private:
    double valueCelsius = 0.0;
    TempUnit unit = TempUnit::CELSIUS;
public:
    double convertToFahrenheit();
    double convertToKelvin();
    bool isBelowZero();
};

class Wind {
private:
    double speed = 0.0;
    double direction = 0.0;
public:
    std::string getDirectionName();
    bool isStrong();
    double getSpeed();
    Temperature calculateWindChill(Temperature temperature);
};

enum class PressureTrend {
    RISING,
    FALLING,
    STEADY
};

class Pressure {
private:
    double valueHPa = 0.0;
    PressureTrend trend = PressureTrend::STEADY;
public:
    double convertToMmHg();
    bool isNormal();
    void predictChange();
};

class Humidity {
private:
    double relativePercent = 0.0;
    double absolute = 0.0;
public:
    Temperature calculateDewPoint(Temperature temperature);
    bool isHigh();
};

enum class PrecipType {
    RAIN,
    SNOW,
    HAIL
};

class Precipitation {
private:
    PrecipType type = PrecipType::RAIN;
    double amountMm = 0.0;
    double intensity = 0.0;
public:
    bool isRain();
    bool isSnow();
    double getAccumulation();
};

enum class CloudType {
    CUMULUS,
    STRATUS,
    CIRRUS,
    CUMULONIMBUS
};

class Cloudiness {
private:
    double coveragePercent = 0.0;
    CloudType cloudType = CloudType::CUMULUS;
public:
    bool isOvercast();
    bool isClear();
};

enum class UVRisk {
    LOW,
    MODERATE,
    HIGH,
    VERY_HIGH,
    EXTREME
};

enum class Comfort {
    DRY,
    COMFORTABLE,
    HUMID,
    OPPRESSIVE
};

enum class WeatherCondition {
    CLEAR,
    PARTLY_CLOUDY,
    CLOUDY,
    RAIN,
    SNOW,
    STORM
};

std::string toString(WeatherCondition condition);
bool isPrecipitation(WeatherCondition condition);

class TimeStamp {
private:
    long long unixTime = 0;
    std::string timezone = "";
public:
    std::string toString();
    bool isDaytime();
    void addHours(int hours);
};

class Weather {
private:
    Temperature temperature;
    Wind wind;
    Pressure pressure;
    Humidity humidity;
    WeatherCondition condition = WeatherCondition::CLEAR;
    TimeStamp timestamp;
public:
    std::string getSummary();
    bool isComfortable();
    void updateFromSensor(Sensor* sensor);
};