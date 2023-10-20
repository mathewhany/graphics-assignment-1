#include "Color.h"
#include <GLUT/glut.h>

Color::Color(double red, double green, double blue) : red(red), green(green), blue(blue) {}

void Color::apply() {
    glColor3d(red, green, blue);
}