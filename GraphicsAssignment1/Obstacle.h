//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_OBSTACLE_H
#define GRAPHICS_OBSTACLE_H


#include "BoundingBox.h"

#include "GameObject.h"
#include "AnimateInPlace.h"

class Obstacle : public GameObject, public BoundingBox {
    double x;
    double y;
    double animAngle;
    AnimateInPlace *animateInPlace;
public:
    static double OBSTACLE_WIDTH;
    static double OBSTACLE_HEIGHT;

    Obstacle(double x, double y);
    void draw() override;

    void animate() override;
};


#endif //GRAPHICS_OBSTACLE_H
