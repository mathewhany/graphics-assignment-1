//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_SPEEDUP_H
#define GRAPHICS_SPEEDUP_H


#include "BoundingBox.h"

#include "GameObject.h"
#include "PowerUp.h"
#include "AnimateInPlace.h"

class SpeedUp : public GameObject, public BoundingBox, public PowerUp {
    double x;
    double y;
    double animScale;
    AnimateInPlace *animateInPlace;
public:
    static double SPEED_UP_WIDTH;
    static double SPEED_UP_HEIGHT;

    SpeedUp(double x, double y, double duration);

    void draw() override;

    void activate(PlayerState *) override;

    void deactivate(PlayerState *) override;

    std::string textMessage() override;

    void animate();
};


#endif //GRAPHICS_SPEEDUP_H
