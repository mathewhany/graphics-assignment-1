//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_COLLECTABLE_H
#define GRAPHICS_COLLECTABLE_H


#include "BoundingBox.h"

#include "GameObject.h"
#include "AnimateInPlace.h"
#include "ObjectWithDuration.h"

class Collectable : public GameObject, public BoundingBox {
    double x;
    double y;
    AnimateInPlace *animateInPlace;
public:
    bool isCollected;

    static double COLLECTABLE_WIDTH;
    static double COLLECTABLE_HEIGHT;

    Collectable(double x, double y);

    void draw() override;

    void animate() override;

    void onTimer() override;
};


#endif //GRAPHICS_COLLECTABLE_H
