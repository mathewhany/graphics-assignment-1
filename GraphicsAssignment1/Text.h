//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_TEXT_H
#define GRAPHICS_TEXT_H

#include <string>
#include "Color.h"
#include <GLUT/glut.h>

class Text {
    double x;
    double y;
    std::string text;

public:
    Text(double x, double y, std::string text, Color color = Color(0, 0, 0), void *font = GLUT_BITMAP_HELVETICA_18);

    void draw();

    Color color;
    void *font;
};


#endif //GRAPHICS_TEXT_H
