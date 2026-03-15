// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPS = 1e-6;


TEST(CircleTest, ConstructorPositiveRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, ConstructorZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, SetRadiusPositive) {
    Circle c(1.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 7.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 49.0, EPS);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusNegative) {
    Circle c(5.0);
    c.setRadius(-3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -3.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, SetFerencePositive) {
    Circle c(1.0);
    c.setFerence(2 * PI * 10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 10.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 100.0, EPS);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle c(5.0);
    c.setFerence(-2 * PI * 4.0);
    EXPECT_NEAR(c.getRadius(), -4.0, EPS);
    EXPECT_NEAR(c.getFerence(), -2 * PI * 4.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(CircleTest, SetAreaPositive) {
    Circle c(1.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPS);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, ConsistencySetRadiusSetFerence) {
    Circle c(10.0);
    double r = c.getRadius();
    double f = c.getFerence();
    c.setFerence(f);
    EXPECT_NEAR(c.getRadius(), r, EPS);
}

TEST(CircleTest, ConsistencySetRadiusSetArea) {
    Circle c(10.0);
    double r = c.getRadius();
    double a = c.getArea();
    c.setArea(a);
    EXPECT_NEAR(c.getRadius(), r, EPS);
}

TEST(CircleTest, ConsistencySetFerenceSetRadius) {
    Circle c(10.0);
    double f = c.getFerence();
    c.setFerence(f);
    double r = c.getRadius();
    c.setRadius(r);
    EXPECT_NEAR(c.getFerence(), f, EPS);
}

TEST(CircleTest, LargeRadius) {
    double r = 1e9;
    Circle c(r);
    EXPECT_NEAR(c.getFerence(), 2 * PI * r, r * EPS);
    EXPECT_NEAR(c.getArea(), PI * r * r, r * r * EPS);
}

TEST(CircleTest, SmallRadius) {
    double r = 1e-9;
    Circle c(r);
    EXPECT_NEAR(c.getFerence(), 2 * PI * r, 1e-15);
    EXPECT_NEAR(c.getArea(), PI * r * r, 1e-24);
}

TEST(CircleTest, MultipleSets) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(2 * PI * 3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
}


TEST(TasksTest, EarthRopeGap) {
    double gap = earthRopeGap();
    double expected = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expected, 1e-6);
    EXPECT_GT(gap, 0.0);
}

TEST(TasksTest, PoolCosts) {
    double concrete, fence;
    poolCosts(concrete, fence);
    double expectedConcrete = 7 * PI * 1000.0;
    double expectedFence = 8 * PI * 2000.0;
    EXPECT_NEAR(concrete, expectedConcrete, 1e-3);
    EXPECT_NEAR(fence, expectedFence, 1e-3);
    EXPECT_GT(concrete, 0.0);
    EXPECT_GT(fence, 0.0);
}
