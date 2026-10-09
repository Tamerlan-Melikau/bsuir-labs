#include <gtest/gtest.h>
#include "forecast.hpp"

TEST(DailyForecastTest, GetAverageTemp) {
    DailyForecast d;
    Temperature t = d.getAverageTemp();
    (void)t;
    SUCCEED();
}

TEST(DailyForecastTest, GetSummaryDefault) {
    DailyForecast d;
    EXPECT_EQ(d.getSummary(), "Daily forecast");
}

TEST(DailyForecastTest, IsRainyDefault) {
    DailyForecast d;
    (void)d.isRainy();
    SUCCEED();
}

TEST(ForecastTest, IsReliableDefault) {
    Forecast f;
    EXPECT_FALSE(f.isReliable());
}

TEST(ForecastTest, GetTemperatureTrendDefault) {
    Forecast f;
    EXPECT_DOUBLE_EQ(f.getTemperatureTrend(), 0.0);
}

TEST(TrendAnalyzerTest, CalculateTrendDefault) {
    TrendAnalyzer ta;
    EXPECT_DOUBLE_EQ(ta.calculateTrend(), 0.0);
}

TEST(TrendAnalyzerTest, GetAverageChangeDefault) {
    TrendAnalyzer ta;
    EXPECT_DOUBLE_EQ(ta.getAverageChange(), 0.0);
}

TEST(TrendAnalyzerTest, IsWarmingDefault) {
    TrendAnalyzer ta;
    EXPECT_FALSE(ta.isWarming());
}

TEST(ProbabilityCalculatorTest, PrecipitationProbabilityDefault) {
    ProbabilityCalculator pc;
    EXPECT_DOUBLE_EQ(pc.calculatePrecipitationProbability(), 0.0);
}

TEST(ProbabilityCalculatorTest, SnowProbabilityDefault) {
    ProbabilityCalculator pc;
    EXPECT_DOUBLE_EQ(pc.calculateSnowProbability(), 0.0);
}

TEST(ProbabilityCalculatorTest, StormProbabilityDefault) {
    ProbabilityCalculator pc;
    EXPECT_DOUBLE_EQ(pc.calculateStormProbability(), 0.0);
}

TEST(HistoryStorageTest, AddAndClear) {
    HistoryStorage hs;
    Weather w;
    hs.addRecord(w);
    hs.addRecord(w);
    auto recs = hs.getRecordsForPeriod(TimeStamp(), TimeStamp());
    EXPECT_EQ(recs.size(), 2u);
    hs.clearOldRecords();
    EXPECT_EQ(hs.getRecordsForPeriod(TimeStamp(), TimeStamp()).size(), 0u);
}

TEST(ForecastModelTest, TrainPredictEvaluate) {
    ForecastModel fm;
    std::vector<Weather> data;
    Weather w;
    data.push_back(w);
    fm.train(data);
    Forecast f = fm.predict(w);
    (void)f;
    EXPECT_DOUBLE_EQ(fm.evaluate(), 0.0);
}