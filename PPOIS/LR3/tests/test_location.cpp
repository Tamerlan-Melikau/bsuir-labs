#include <gtest/gtest.h>
#include "location.hpp"

TEST(GeoCoordinateTest, IsValidDefault) {
    GeoCoordinate c;
    EXPECT_TRUE(c.isValid());
}

TEST(GeoCoordinateTest, DistanceToSelfIsZero) {
    GeoCoordinate a, b;
    EXPECT_NEAR(a.distanceTo(b), 0.0, 0.001);
}

TEST(LocationTest, GetLocalTimeDefault) {
    Location l;
    EXPECT_EQ(l.getLocalTime(), "");
}

TEST(LocationTest, GetNameDefault) {
    Location l;
    EXPECT_EQ(l.getName(), "");
}

TEST(CityTest, GetPopulationDefault) {
    City c;
    EXPECT_EQ(c.getPopulation(), 0);
}

TEST(CityTest, IsCapitalDefault) {
    City c;
    EXPECT_FALSE(c.isCapital());
}

TEST(RegionTest, AddCityAndGetName) {
    Region r;
    City c;
    r.addCity(c);
    EXPECT_EQ(r.getName(), "");
}

TEST(RegionTest, GetAverageTemperatureDefault) {
    Region r;
    EXPECT_DOUBLE_EQ(r.getAverageTemperature(), 0.0);
}

TEST(CountryTest, GetRegionCountDefault) {
    Country c;
    EXPECT_EQ(c.getRegionCount(), 0);
}

TEST(CountryTest, FindRegionNotFound) {
    Country c;
    EXPECT_EQ(c.findRegion("nonexistent"), nullptr);
}

TEST(AddressTest, GetFullAddressDefault) {
    Address a;
    (void)a.getFullAddress();
    SUCCEED();
}

TEST(AddressTest, IsValidDefault) {
    Address a;
    EXPECT_FALSE(a.isValid());
}