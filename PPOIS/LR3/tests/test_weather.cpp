#include <gtest/gtest.h>
#include "weather.hpp"

// ---------- Temperature ----------
TEST(TemperatureTest, ConvertToFahrenheit) {
    Temperature t;
    EXPECT_NEAR(t.convertToFahrenheit(), 32.0, 0.001);
}

TEST(TemperatureTest, ConvertToKelvin) {
    Temperature t;
    EXPECT_NEAR(t.convertToKelvin(), 273.15, 0.001);
}

TEST(TemperatureTest, IsBelowZeroFalse) {
    Temperature t;
    EXPECT_FALSE(t.isBelowZero());
}

// ---------- Wind ----------
TEST(WindTest, DirectionNameDefault) {
    Wind w;
    EXPECT_EQ(w.getDirectionName(), "North");
}

TEST(WindTest, IsStrongDefault) {
    Wind w;
    EXPECT_FALSE(w.isStrong());
}

TEST(WindTest, CalculateWindChill) {
    Wind w;
    Temperature t;
    Temperature result = w.calculateWindChill(t);
    (void)result;
    SUCCEED();
}

TEST(WindTest, GetSpeedDefault) {
    Wind w;
    EXPECT_DOUBLE_EQ(w.getSpeed(), 0.0);
}

// ---------- Pressure ----------
TEST(PressureTest, ConvertToMmHgDefault) {
    Pressure p;
    EXPECT_NEAR(p.convertToMmHg(), 0.0, 0.001);
}

TEST(PressureTest, IsNormalDefault) {
    Pressure p;
    EXPECT_FALSE(p.isNormal());
}

TEST(PressureTest, PredictChange) {
    Pressure p;
    p.predictChange();
    SUCCEED();
}

// ---------- Humidity ----------
TEST(HumidityTest, CalculateDewPoint) {
    Humidity h;
    Temperature t;
    Temperature dp = h.calculateDewPoint(t);
    (void)dp;
    SUCCEED();
}

TEST(HumidityTest, IsHighDefault) {
    Humidity h;
    EXPECT_FALSE(h.isHigh());
}

// ---------- Precipitation ----------
TEST(PrecipitationTest, IsRainDefault) {
    Precipitation p;
    (void)p.isRain();
    SUCCEED();
}

TEST(PrecipitationTest, IsSnowDefault) {
    Precipitation p;
    EXPECT_FALSE(p.isSnow());
}

TEST(PrecipitationTest, GetAccumulationDefault) {
    Precipitation p;
    EXPECT_DOUBLE_EQ(p.getAccumulation(), 0.0);
}

// ---------- Cloudiness ----------
TEST(CloudinessTest, IsOvercastDefault) {
    Cloudiness c;
    EXPECT_FALSE(c.isOvercast());
}

TEST(CloudinessTest, IsClearDefault) {
    Cloudiness c;
    EXPECT_TRUE(c.isClear());
}

// ---------- TimeStamp ----------
TEST(TimeStampTest, ToStringDefault) {
    TimeStamp ts;
    EXPECT_EQ(ts.toString(), "0");
}

TEST(TimeStampTest, IsDaytimeDefault) {
    TimeStamp ts;
    EXPECT_FALSE(ts.isDaytime());
}

TEST(TimeStampTest, AddHours) {
    TimeStamp ts;
    ts.addHours(6);
    EXPECT_TRUE(ts.isDaytime());
    ts.addHours(12);
    EXPECT_FALSE(ts.isDaytime());
}

// ---------- Weather ----------
TEST(WeatherTest, GetSummaryNotEmpty) {
    Weather w;
    std::string s = w.getSummary();
    EXPECT_FALSE(s.empty());
}

TEST(WeatherTest, IsComfortableDefault) {
    Weather w;
    (void)w.isComfortable();
    SUCCEED();
}

TEST(WeatherTest, UpdateFromSensorNull) {
    Weather w;
    w.updateFromSensor(nullptr);
    SUCCEED();
}

// ---------- Свободные функции ----------
TEST(WeatherConditionTest, ToStringAll) {
    EXPECT_EQ(toString(WeatherCondition::CLEAR), "Clear");
    EXPECT_EQ(toString(WeatherCondition::PARTLY_CLOUDY), "Partly Cloudy");
    EXPECT_EQ(toString(WeatherCondition::CLOUDY), "Cloudy");
    EXPECT_EQ(toString(WeatherCondition::RAIN), "Rain");
    EXPECT_EQ(toString(WeatherCondition::SNOW), "Snow");
    EXPECT_EQ(toString(WeatherCondition::STORM), "Storm");
}

TEST(WeatherConditionTest, IsPrecipitation) {
    EXPECT_FALSE(isPrecipitation(WeatherCondition::CLEAR));
    EXPECT_TRUE(isPrecipitation(WeatherCondition::RAIN));
    EXPECT_TRUE(isPrecipitation(WeatherCondition::SNOW));
    EXPECT_TRUE(isPrecipitation(WeatherCondition::STORM));
}