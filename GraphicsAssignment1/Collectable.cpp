//
// Created by Mathew Hany on 15/10/2023.
//

#include "Collectable.h"
#include "Color.h"
#include "Rectangle.h"
#include <GLUT/glut.h>
#include <cstdlib>
#include "AnimateInPlace.h"

double Collectable::COLLECTABLE_WIDTH = 25;
double Collectable::COLLECTABLE_HEIGHT = 25;

Collectable::Collectable(double x, double y)
        : BoundingBox(x, y, COLLECTABLE_WIDTH, COLLECTABLE_HEIGHT),
          x(x), y(y),
          isCollected(false) {
    animateInPlace = new AnimateInPlace(3, &this->y);
}

void Collectable::draw() {
    if (isCollected) {
        return;
    }

    glPushMatrix();
    glTranslated(x, y, 0);

    GLUquadric *quad = gluNewQuadric();
    glColor3d(0.95, 0.95, 0);
    gluDisk(quad, 0, COLLECTABLE_WIDTH / 2, 250, 250);
    Rectangle(0, 0, 5, 15, Color(1, 0.4, 0)).draw();

    glBegin(GL_TRIANGLES);
    glColor3d(1, 0.5, 0);
    glVertex2d(0, COLLECTABLE_WIDTH / 2);
    glVertex2d(COLLECTABLE_WIDTH / 2, COLLECTABLE_WIDTH / 2 + 5);
    glVertex2d(-COLLECTABLE_WIDTH / 2, COLLECTABLE_WIDTH / 2 + 5);
    glEnd();


    glPopMatrix();
}

void Collectable::animate() {
    animateInPlace->animate();
}

void Collectable::onTimer() {
    double time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
}

