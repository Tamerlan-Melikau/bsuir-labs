#include "forecast.hpp"

Temperature DailyForecast::getAverageTemp() {
    Temperature result;
    return result;
}

std::string DailyForecast::getSummary() {
    return "Daily forecast";
}

bool DailyForecast::isRainy() {
    return precipitation.isRain();
}

DailyForecast Forecast::getDailyForecast(int day) {
    return daily[day];
}

double Forecast::getTemperatureTrend() {
    return 0.0;
}

bool Forecast::isReliable() {
    return confidence > 0.7;
}

double TrendAnalyzer::calculateTrend() {
    return 0.0;
}

double TrendAnalyzer::getAverageChange() {
    return 0.0;
}

bool TrendAnalyzer::isWarming() {
    return calculateTrend() > 0.0;
}

double ProbabilityCalculator::calculatePrecipitationProbability() {
    return 0.0;
}

double ProbabilityCalculator::calculateSnowProbability() {
    return 0.0;
}

double ProbabilityCalculator::calculateStormProbability() {
    return 0.0;
}

void HistoryStorage::addRecord(Weather w) {
    if ((int)records.size() >= maxSize) {
        records.erase(records.begin());
    }
    records.push_back(w);
}

std::vector<Weather> HistoryStorage::getRecordsForPeriod(TimeStamp t1, TimeStamp t2) {
    return records;
}

void HistoryStorage::clearOldRecords() {
    records.clear();
}

void ForecastModel::train(std::vector<Weather> data) {
    accuracy = 0.0;
}

Forecast ForecastModel::predict(Weather w) {
    Forecast f;
    return f;
}

double ForecastModel::evaluate() {
    return accuracy;
}