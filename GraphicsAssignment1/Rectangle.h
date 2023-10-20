//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_RECTANGLE_H
#define GRAPHICS_RECTANGLE_H

#include "Color.h"

class Rectangle {
    double x, y, width, height;
    Color color;
    bool xyIsCenter;

public:
    Rectangle(double x, double y, double width, double height, Color color, bool xyIsCenter = true);
    void draw();
};


#endif //GRAPHICS_RECTANGLE_H
