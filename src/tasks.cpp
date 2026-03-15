// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthRopeGap() {
    const double earthRadius = 6378100.0;
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + 1.0;
    earth.setFerence(newFerence);
    return earth.getRadius() - earthRadius;
}

void poolCosts(double& concreteCost, double& fenceCost) {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double outerRadius = poolRadius + pathWidth;

    Circle pool(poolRadius);
    Circle outer(outerRadius);

    double pathArea = outer.getArea() - pool.getArea();
    concreteCost = pathArea * 1000.0;

    double fenceLength = outer.getFerence();
    fenceCost = fenceLength * 2000.0;
}
