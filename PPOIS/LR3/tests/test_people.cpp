#include <gtest/gtest.h>
#include "people.hpp"

TEST(HumanTest, ShowInfoDefault) {
    Human h;
    EXPECT_EQ(h.showInfo(), "");
}

TEST(UserTest, LoginEmptyMatchesEmpty) {
    User u;
    EXPECT_TRUE(u.login("", ""));
}

TEST(UserTest, LoginWrongCredentials) {
    User u;
    EXPECT_FALSE(u.login("x", "y"));
}

TEST(UserTest, Logout) {
    User u;
    u.logout();
    SUCCEED();
}

TEST(UserTest, AddAndRemoveFavorite) {
    User u;
    Location l;
    u.addFavorite(l);
    u.removeFavorite(l);
    SUCCEED();
}

TEST(WorkerTest, IsVacationDefault) {
    Worker w;
    EXPECT_FALSE(w.isVacation());
}

TEST(WorkerTest, GetSalaryDefault) {
    Worker w;
    EXPECT_EQ(w.getSalary(), 0);
}

TEST(AdminTest, BlockUser) {
    Admin a;
    User u;
    a.blockUser(u);
    SUCCEED();
}

TEST(AdminTest, ViewLogsDefault) {
    Admin a;
    EXPECT_EQ(a.viewLogs(), 0);
}

TEST(MasterTest, RepairStation) {
    Master m;
    WeatherStation s;
    EXPECT_TRUE(m.repairStation(s));
}

TEST(MasterTest, ReplaceSensorValidAndNull) {
    Master m;
    Thermometer t;
    m.replaceSensor(&t);
    m.replaceSensor(nullptr);
    SUCCEED();
}

TEST(MasterTest, RequestParts) {
    Master m;
    m.requestParts();
    SUCCEED();
}

TEST(SupervisorTest, ReviewWork) {
    Supervisor s;
    s.reviewWork();
    SUCCEED();
}