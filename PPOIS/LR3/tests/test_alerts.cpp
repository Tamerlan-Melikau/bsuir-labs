#include <gtest/gtest.h>
#include "alerts.hpp"

TEST(AlertTest, IsActiveDefault) {
    Alert a;
    EXPECT_TRUE(a.isActive());
}

TEST(AlertTest, GetFullTextDefault) {
    Alert a;
    EXPECT_EQ(a.getFullText(), "");
}

TEST(AlertCriteriaTest, MatchesDefault) {
    AlertCriteria ac;
    Weather w;
    EXPECT_FALSE(ac.matches(w));
}

TEST(EmailNotifierTest, ValidateEmailValid) {
    EmailNotifier en;
    EXPECT_TRUE(en.validateEmail("a@b.com"));
}

TEST(EmailNotifierTest, ValidateEmailInvalid) {
    EmailNotifier en;
    EXPECT_FALSE(en.validateEmail("ab.com"));
}

TEST(EmailNotifierTest, SendValid) {
    EmailNotifier en;
    EXPECT_TRUE(en.send("a@b.com", "msg"));
}

TEST(EmailNotifierTest, SendInvalid) {
    EmailNotifier en;
    EXPECT_FALSE(en.send("invalid", "msg"));
}