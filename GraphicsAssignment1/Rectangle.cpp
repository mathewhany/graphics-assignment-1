//
// Created by Mathew Hany on 15/10/2023.
//

#include "Rectangle.h"
#include <GLUT/glut.h>

Rectangle::Rectangle(double x, double y, double width, double height, Color color, bool xyIsCenter)
        : x(x), y(y), width(width),
          height(height), color(color), xyIsCenter(xyIsCenter) {}

void Rectangle::draw() {
    color.apply();
    glBegin(GL_POLYGON);
    if (xyIsCenter) {
        glVertex2d(x - width / 2, y - height / 2);
        glVertex2d(x + width / 2, y - height / 2);
        glVertex2d(x + width / 2, y + height / 2);
        glVertex2d(x - width / 2, y + height / 2);
    } else {
        glVertex2d(x, y);
        glVertex2d(x + width, y);
        glVertex2d(x + width, y + height);
        glVertex2d(x, y + height);
    }
    glEnd();
}