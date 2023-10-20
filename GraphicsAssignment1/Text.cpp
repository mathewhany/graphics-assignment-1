//
// Created by Mathew Hany on 15/10/2023.
//

#include "Text.h"
#include <GLUT/glut.h>
#include "Color.h"

Text::Text(double x, double y, std::string text, Color color, void *font) : x(x), y(y), text(text), color(color), font(font) {}

void Text::draw() {
    color.apply();
    glRasterPos2d(x, y);

    for (char &letter: text) {
        glutBitmapCharacter(font, letter);
    }
}
