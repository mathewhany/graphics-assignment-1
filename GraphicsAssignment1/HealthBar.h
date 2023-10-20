//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_HEALTHBAR_H
#define GRAPHICS_HEALTHBAR_H



#include "GameObject.h"
#include "PlayerState.h"

class HealthBar : public GameObject {
private:
    double x;
    double y;
    int maxHealth;
    PlayerState *playerState;

public:
    static double HEALTH_BAR_WIDTH;
    static double HEALTH_BAR_HEIGHT;

    HealthBar(double x, double y, int maxHealth, PlayerState *playerState);

    void draw() override;
};


#endif //GRAPHICS_HEALTHBAR_H
