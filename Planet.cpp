//
// Created by Evan Laube on 11/10/22.
//

#include "Planet.h"

Planet::Planet(double x, double y, double mass) {
    Planet::x = x;
    Planet::y = y;
    Planet::mass = mass;

    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
}

void Planet::setVelocity(double vx, double vy) {
    Planet::vx = vx;
    Planet::vy = vy;
}

void Planet::addForce(double fx, double fy) {
    ax += fx/mass;
    ay += fy/mass;
}

void Planet::update(double timeStep) {
    x += vx*timeStep;
    y += vy*timeStep;

    vx += ax*timeStep;
    vy += ay*timeStep;

    ax = 0;
    ay = 0;
}