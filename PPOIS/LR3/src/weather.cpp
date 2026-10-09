#include "weather.hpp"
#include <sstream>
#include <cmath>

double Temperature::convertToFahrenheit(){
    return valueCelsius * 9.0 / 5.0 + 32.0;
}

double Temperature::convertToKelvin(){
    return valueCelsius + 273.15;
}

bool Temperature::isBelowZero(){
    return valueCelsius < 0.0;
}

std::string Wind::getDirectionName(){
    if (direction >= 337.5 || direction < 22.5) return "North";
    if (direction < 67.5) return "North-East";
    if (direction < 112.5) return "East";
    if (direction < 157.5) return "South-East";
    if (direction < 202.5) return "South";
    if (direction < 247.5) return "South-West";
    if (direction < 292.5) return "West";
    return "North-West";
}

bool Wind::isStrong(){
    return speed > 10.0;
}

Temperature Wind::calculateWindChill(Temperature temperature){
    Temperature result;
    double t = temperature.convertToFahrenheit();
    double chill = 35.74 + 0.6215 * t - 35.75 * std::pow(speed, 0.16)
                   + 0.4275 * t * std::pow(speed, 0.16);
    return result;
}

double Pressure::convertToMmHg(){
    return valueHPa * 0.750062;
}

bool Pressure::isNormal(){
    return valueHPa >= 1000.0 && valueHPa <= 1025.0;
}

void Pressure::predictChange(){
    if(trend == PressureTrend::FALLING){
    }else if(trend == PressureTrend::RISING){}
}

Temperature Humidity::calculateDewPoint(Temperature temperature){
    Temperature result;
    double t = temperature.convertToFahrenheit();
    double dp = t - (100.0 - relativePercent) / 5.0;
    return result;
}

bool Humidity::isHigh(){
    return relativePercent > 70.0;
}

bool Precipitation::isRain(){
    return type == PrecipType::RAIN;
}

bool Precipitation::isSnow(){
    return type == PrecipType::SNOW;
}

double Precipitation::getAccumulation(){
    return amountMm * intensity;
}

bool Cloudiness::isOvercast(){
    return coveragePercent > 90.0;
}

bool Cloudiness::isClear(){
    return coveragePercent < 10.0;
}

std::string TimeStamp::toString(){
    return std::to_string(unixTime);
}

bool TimeStamp::isDaytime(){
    long long hour = (unixTime / 3600) % 24;
    return hour >= 6 && hour < 18;
}

void TimeStamp::addHours(int hours){
    unixTime += hours * 3600;
}

std::string Weather::getSummary(){
    std::stringstream ss;
    ss << "Temp: " << temperature.convertToFahrenheit() << "F, ";
    ss << "Wind: " << wind.getDirectionName() << " " << wind.getSpeed();
    return ss.str();
}

bool Weather::isComfortable(){
    return !temperature.isBelowZero() && !humidity.isHigh() && !wind.isStrong();
}

void Weather::updateFromSensor(Sensor* sensor){
    if (sensor == nullptr || !sensor->isValid()) return;
    double value = sensor->readValue();
}

std::string toString(WeatherCondition condition) {
    switch (condition) {
        case WeatherCondition::CLEAR: return "Clear";
        case WeatherCondition::PARTLY_CLOUDY: return "Partly Cloudy";
        case WeatherCondition::CLOUDY: return "Cloudy";
        case WeatherCondition::RAIN: return "Rain";
        case WeatherCondition::SNOW: return "Snow";
        case WeatherCondition::STORM: return "Storm";
    }
    return "Unknown";
}

bool isPrecipitation(WeatherCondition condition) {
    return condition == WeatherCondition::RAIN ||
           condition == WeatherCondition::SNOW ||
           condition == WeatherCondition::STORM;
}

double Wind::getSpeed() {
    return speed;
}