//
// Created by Evan Laube on 11/10/22.
//

#ifndef LAUBSTERVERSE_PLANET_H
#define LAUBSTERVERSE_PLANET_H


class Planet {

public:
    double x, y;
    double vx, vy;
    double ax, ay;
    double mass;

    Planet(double x, double y, double mass);

    void addForce(double fx, double fy);
    void setVelocity(double vx, double vy);
    void update(double timeStep);

};

#endif //LAUBSTERVERSE_PLANET_H
