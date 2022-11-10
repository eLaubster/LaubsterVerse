//
// Created by Evan Laube on 11/10/22.
//

#ifndef LAUBSTERVERSE_SPACE_H
#define LAUBSTERVERSE_SPACE_H

#include <vector>
#include "Planet.h"

class Space {

public:
    std::vector<Planet> planets;


    const double G = .00000000006674;

    Space();
    void addPlanet(Planet p);

    void update(double timeStep);

    double distance(Planet a, Planet b);
};

#endif //LAUBSTERVERSE_SPACE_H
