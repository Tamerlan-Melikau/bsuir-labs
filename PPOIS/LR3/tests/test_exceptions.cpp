#include <gtest/gtest.h>
#include "exceptions.hpp"

TEST(WeatherExceptionTest, WhatAndCode) {
    WeatherException e("test", 42);
    EXPECT_STREQ(e.what(), "test");
    EXPECT_EQ(e.getCode(), 42);
}

TEST(NetworkExceptionTest, IsTimeoutTrue) {
    NetworkException e("msg", 1, "url", 0);
    EXPECT_TRUE(e.isTimeout());
}

TEST(NetworkExceptionTest, IsTimeoutFalse) {
    NetworkException e("msg", 1, "url", 5000);
    EXPECT_FALSE(e.isTimeout());
}

TEST(ApiExceptionTest, IsRateLimitTrue) {
    ApiException e("msg", 1, 429, "api");
    EXPECT_TRUE(e.isRateLimit());
}

TEST(ApiExceptionTest, IsRateLimitFalse) {
    ApiException e("msg", 1, 500, "api");
    EXPECT_FALSE(e.isRateLimit());
}

TEST(ParseExceptionTest, GetPosition) {
    ParseException e("msg", 1, "data", 10);
    EXPECT_EQ(e.getPosition(), 10);
}

TEST(AuthExceptionTest, IsBlockedTrue) {
    AuthException e("msg", 1, "login", 3);
    EXPECT_TRUE(e.isBlocked());
}

TEST(AuthExceptionTest, IsBlockedFalse) {
    AuthException e("msg", 1, "login", 2);
    EXPECT_FALSE(e.isBlocked());
}

TEST(NotFoundExceptionTest, GetFullMessage) {
    NotFoundException e("msg", 1, "User", "42");
    EXPECT_EQ(e.getFullMessage(), "User 42 not found");
}

TEST(InvalidDataExceptionTest, GetField) {
    InvalidDataException e("msg", 1, "temperature", "abc");
    EXPECT_EQ(e.getField(), "temperature");
}

TEST(StorageExceptionTest, IsReadOnlyTrue) {
    StorageException e("msg", 1, "/path", "write");
    EXPECT_TRUE(e.isReadOnly());
}

TEST(StorageExceptionTest, IsReadOnlyFalse) {
    StorageException e("msg", 1, "/path", "read");
    EXPECT_FALSE(e.isReadOnly());
}

TEST(SensorExceptionTest, NeedsReplacementTrue) {
    SensorException e("msg", 1, "id", 101);
    EXPECT_TRUE(e.needsReplacement());
}

TEST(SensorExceptionTest, NeedsReplacementFalse) {
    SensorException e("msg", 1, "id", 50);
    EXPECT_FALSE(e.needsReplacement());
}

TEST(ForecastExceptionTest, IsLowConfidenceTrue) {
    ForecastException e("msg", 1, "model", 0.3);
    EXPECT_TRUE(e.isLowConfidence());
}

TEST(ForecastExceptionTest, IsLowConfidenceFalse) {
    ForecastException e("msg", 1, "model", 0.8);
    EXPECT_FALSE(e.isLowConfidence());
}

TEST(UserExceptionTest, GetUserAction) {
    UserException e("msg", 1, "id", "login");
    EXPECT_EQ(e.getUserAction(), "login");
}

TEST(ConfigExceptionTest, GetParam) {
    ConfigException e("msg", 1, "timeout", "network");
    EXPECT_EQ(e.getParam(), "timeout");
}