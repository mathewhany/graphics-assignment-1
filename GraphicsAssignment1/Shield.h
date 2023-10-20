//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_SHIELD_H
#define GRAPHICS_SHIELD_H


#include "BoundingBox.h"

#include "GameObject.h"
#include "PowerUp.h"
#include "AnimateInPlace.h"

class Shield : public GameObject, public BoundingBox, public PowerUp {
    double x;
    double y;
    AnimateInPlace *animateInPlace;

public:
    static double SHIELD_WIDTH;
    static double SHIELD_HEIGHT;

    Shield(double x, double y, double duration);

    void draw() override;

    void activate(PlayerState *playerState) override;

    void deactivate(PlayerState *playerState) override;

    std::string textMessage() override;

    void animate() override;
};


#endif //GRAPHICS_SHIELD_H
