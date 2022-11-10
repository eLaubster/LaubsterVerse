//
// Created by Evan Laube on 11/10/22.
//

#include <cmath>
#include "Space.h"

// Only for debug
#include <iostream>
using namespace std;

Space::Space() {
    planets = {};
}

void Space::addPlanet(Planet p) {
    planets.push_back(p);
}

void Space::update(double timeStep) {
    int i = 0;
    for(auto &a : planets) {
        for(auto &b : planets) {

            if(&a != &b) {
                double dx = b.x - a.x;
                double dy = b.y - a.y;

                double dist = distance(a,b);

                double mag = (G * a.mass * b.mass) / pow(dist, 2);

                if(dx < 0) {
                    mag *= -1;
                }

                double t = atan(dy / dx);
                double fx = mag * cos(t);
                double fy = mag * sin(t);

                a.addForce(fx, fy);
            }
        }
        a.update(timeStep);
    }
}

double Space::distance(Planet a, Planet b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}