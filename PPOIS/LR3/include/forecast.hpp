#pragma once
#include "weather.hpp"
#include <vector>

class DailyForecast {
private:
    Temperature minTemp;
    Temperature maxTemp;
    TimeStamp date;
    Precipitation precipitation;
    Wind wind;
    WeatherCondition condition = WeatherCondition::CLEAR;
public:
    Temperature getAverageTemp();
    std::string getSummary();
    bool isRainy();
};

class Forecast {
private:
    Location location;
    TimeStamp created;
    TimeStamp validUntil;
    std::vector<DailyForecast> daily;
    double confidence = 0.0;
public:
    DailyForecast getDailyForecast(int day);
    double getTemperatureTrend();
    bool isReliable();
};

class TrendAnalyzer {
private:
    std::vector<Weather> history;
    int period = 0;
public:
    double calculateTrend();
    double getAverageChange();
    bool isWarming();
};

class ProbabilityCalculator {
private:
    std::vector<Weather> historicalData;
    Location location;
public:
    double calculatePrecipitationProbability();
    double calculateSnowProbability();
    double calculateStormProbability();
};

class HistoryStorage {
private:
    std::vector<Weather> records;
    int maxSize = 100;
public:
    void addRecord(Weather);
    std::vector<Weather> getRecordsForPeriod(TimeStamp, TimeStamp);
    void clearOldRecords();
};

class ForecastModel {
private:
    std::string name = "";
    std::string version = "";
    double accuracy = 0.0;
public:
    void train(std::vector<Weather>);
    Forecast predict(Weather);
    double evaluate();
};