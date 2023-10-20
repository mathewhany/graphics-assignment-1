//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GAMETIMEPANE_H
#define GRAPHICS_GAMETIMEPANE_H


#include "GameObject.h"


class GameTimePane : public GameObject {
    double x;
    double y;
    int startTime;
public :
    GameTimePane(double x, double y);

    void draw() override;
};


#endif //GRAPHICS_GAMETIMEPANE_H
