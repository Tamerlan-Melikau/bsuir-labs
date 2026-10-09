#include <gtest/gtest.h>
#include "sources.hpp"

TEST(DataSourceTest, FetchDataDefault) {
    DataSource ds;
    Weather w = ds.fetchData();
    (void)w;
    SUCCEED();
}

TEST(DataSourceTest, IsAvailableDefault) {
    DataSource ds;
    EXPECT_FALSE(ds.isAvailable());
}

TEST(SatelliteSourceTest, DownloadImage) {
    SatelliteSource ss;
    ss.downloadImage();
    SUCCEED();
}

TEST(SatelliteSourceTest, ProcessImage) {
    SatelliteSource ss;
    Weather w = ss.processImage();
    (void)w;
    SUCCEED();
}

TEST(WeatherStationTest, ShowAdresDefault) {
    WeatherStation ws;
    EXPECT_EQ(ws.showAdres(), "");
}

TEST(WeatherStationTest, ReadSensorsDefault) {
    WeatherStation ws;
    Weather w = ws.readSensors();
    (void)w;
    SUCCEED();
}

TEST(WeatherStationTest, CalibrateAllEmpty) {
    WeatherStation ws;
    ws.calibrateAll();
    SUCCEED();
}