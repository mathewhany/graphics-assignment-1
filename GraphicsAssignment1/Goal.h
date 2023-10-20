//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GOAL_H
#define GRAPHICS_GOAL_H


#include "BoundingBox.h"

#include "GameObject.h"
#include "AnimateInPlace.h"

class Goal : public GameObject, public BoundingBox {
    double x;
    double y;
    double animScale;
    AnimateInPlace *animateInPlace;
public:
    static double GOAL_WIDTH;
    static double GOAL_HEIGHT;

    Goal(double x, double y);

    void draw() override;

    void animate();
};


#endif //GRAPHICS_GOAL_H
