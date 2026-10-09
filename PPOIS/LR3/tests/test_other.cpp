#include <gtest/gtest.h>
#include "other.hpp"

TEST(TowerTest, NeedsRepairEmptySensors) {
    Tower t;
    EXPECT_FALSE(t.needsRepair());
}

TEST(TowerTest, GetSensorCountDefault) {
    Tower t;
    EXPECT_EQ(t.getSensorCount(), 0);
}

TEST(MaintenanceTaskTest, IsOverdueDefault) {
    MaintenanceTask mt;
    EXPECT_TRUE(mt.isOverdue());
}