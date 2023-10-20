//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_POWERUPSPANE_H
#define GRAPHICS_POWERUPSPANE_H


#include "GameObject.h"

#include "PowerUp.h"

class PowerUpsPane : public GameObject {
    double x;
    double y;
    std::vector<PowerUp *> *appliedPowerUps;
public:
    static double POWER_UP_PANE_HEIGHT;
    static double POWER_UP_PANE_WIDTH;

    PowerUpsPane(double x, double y, std::vector<PowerUp *> *appliedPowerUps);

    void draw() override;
};


#endif //GRAPHICS_POWERUPSPANE_H
