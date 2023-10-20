//
// Created by Mathew Hany on 16/10/2023.
//

#ifndef GRAPHICS_GAMEBOUNDARY_H
#define GRAPHICS_GAMEBOUNDARY_H


#include "GameObject.h"
#include "BoundingBox.h"

class GameBoundary : public GameObject, public BoundingBox {
    double x;
    double y;
    double width;
    double height;
public:
    GameBoundary(double x, double y, double width, double height);

    void draw() override;
};


#endif //GRAPHICS_GAMEBOUNDARY_H
