//
// Created by Mathew Hany on 20/10/2023.
//

#ifndef GRAPHICS_CLOUDS_H
#define GRAPHICS_CLOUDS_H


#include "GameObject.h"

class Clouds : public GameObject {
    double x;
    double y;
    double scale;

public:
    Clouds(double x, double y, double d);

    void draw() override;

    void animate() override;
};


#endif //GRAPHICS_CLOUDS_H
