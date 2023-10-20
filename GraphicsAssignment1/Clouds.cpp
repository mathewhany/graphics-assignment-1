//
// Created by Mathew Hany on 20/10/2023.
//

#include "Clouds.h"
#include <GLUT/glut.h>
#include <cstdlib>

Clouds::Clouds(double x, double y, double scale) : x(x), y(y), scale(scale) {}

void Clouds::draw() {
    glPushMatrix();
    glScaled(scale, scale, 0);
    glTranslated(x, y, 0);
    glPushMatrix();
    glTranslated(-25, 0, 0);
    glColor3f(1, 1, 1);
    gluDisk(gluNewQuadric(), 0, 25, 250, 250);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 0, 0);
    glColor3f(1, 1, 1);
    gluDisk(gluNewQuadric(), 0, 30, 250, 250);
    glPopMatrix();
    glPushMatrix();
    glTranslated(25, 0, 0);
    glColor3f(1, 1, 1);
    gluDisk(gluNewQuadric(), 0, 20, 250, 250);
    glPopMatrix();
    glPopMatrix();
}

void Clouds::animate() {
    x += 0.5;
    if (x > 1000) {
        x = -1000;
    }
}

