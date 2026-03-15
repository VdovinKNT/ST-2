// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    radius_ = radius;
    double absRadius = std::fabs(radius);
    ference_ = 2 * PI * absRadius;
    area_ = PI * absRadius * absRadius;
}

void Circle::setFerence(double ference) {
    ference_ = ference;
    radius_ = ference_ / (2 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::setArea(double area) {
    area_ = area;
    radius_ = std::sqrt(area_ / PI);
    ference_ = 2 * PI * radius_;
}

double Circle::getRadius() const { return radius_; }
double Circle::getFerence() const { return ference_; }
double Circle::getArea() const { return area_; }
