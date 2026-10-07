#pragma once
#include "weather.hpp"
#include <vector>

class DailyForecast{
private:
    Temperature minTemp, maxTemp;
    TimeStamp date;
    Precipitation precipitation;
    Wind wind;
    WeatherCondition condition;
public:
    Temperature getAverageTemp();
    std::string getSummary();
    bool isRainy();
};

class Forecast{
private:
    Location location;
    TimeStamp created, validUntil;
    std::vector<DailyForecast> daily;
    double confidence;
public:
    DailyForecast getDailyForecast(int day);
    double getTemperatureTrend();
    bool isReliable();
};

class HourlyForecast{
private:
    Temperature temperature;
    TimeStamp time;
    Precipitation precipitation;
    Wind wind;
    WeatherCondition condition;
public:
    Temperature getFeelsLike();
    bool isDaytime();
    bool isPrecipitation();
};

class TrendAnalyzer{
private:
    std::vector<Weather> history;
    int period;
public:
    double calculateTrend();
    double getAverageChange();
    bool isWarming();
};

class ProbabilityCalculator{
private:
    std::vector<Weather> historicalData;
    Location location;
public:
    double calculatePrecipitationProbability();
    double calculateSnowProbability();
    double calculateStormProbability();
};

class HistoryStorage{
private:
    std::vector<Weather> records;
    int maxSize;
public:
    void addRecord(Weather);
    std::vector<Weather> getRecordsForPeriod(TimeStamp, TimeStamp);
    void clearOldRecords();
};

class ForecastModel{
private:
    std::string name;
    std::string version;
    double accuracy;
public:
    void train(std::vector<Weather>);
    Forecast predict(Weather);
    double evaluate();
};

class ForecastAccuracy{
private:
    Weather predicted;
    Weather actual;
    double error;
public:
    double calculateError();
    bool isAcceptable();
};