#include <gtest/gtest.h>
#include "sensors.hpp"
#include "weather.hpp"

TEST(SensorTest, ReadValueDefault) {
    Sensor s;
    EXPECT_DOUBLE_EQ(s.readValue(), 0.0);
}

TEST(SensorTest, CalibrateThenIsValid) {
    Sensor s;
    s.calibrate();
    EXPECT_TRUE(s.isValid());
}

TEST(ThermometerTest, ReadTemperatureDefault) {
    Thermometer t;
    EXPECT_DOUBLE_EQ(t.readTemperature(), 0.0);
}

TEST(BarometerTest, ReadPressureDefault) {
    Barometer b;
    EXPECT_DOUBLE_EQ(b.readPressure(), 0.0);
}

TEST(AnemometerTest, ReadWindSpeedDefault) {
    Anemometer a;
    EXPECT_DOUBLE_EQ(a.readWindSpeed(), 0.0);
}

TEST(AnemometerTest, ReadWindDirectionDefault) {
    Anemometer a;
    EXPECT_DOUBLE_EQ(a.readWindDirection(), 0.0);
}

TEST(HygrometerTest, ReadHumidityDefault) {
    Hygrometer h;
    EXPECT_DOUBLE_EQ(h.readHumidity(), 0.0);
}

TEST(SensorNetworkTest, AddAndPoll) {
    SensorNetwork net;
    Thermometer t;
    net.addSensor(&t);
    net.pollAll();
    EXPECT_EQ(net.getActiveSensors(), 0);
    t.calibrate();
    EXPECT_EQ(net.getActiveSensors(), 1);
}

TEST(SensorNetworkTest, AddNull) {
    SensorNetwork net;
    net.addSensor(nullptr);
    net.pollAll();
    EXPECT_EQ(net.getActiveSensors(), 0);
}

TEST(CalibrationToolTest, RunCalibration) {
    CalibrationTool ct;
    ct.runCalibration();
    SUCCEED();
}