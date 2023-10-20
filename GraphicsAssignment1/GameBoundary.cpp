//
// Created by Mathew Hany on 16/10/2023.
//

#include "GameBoundary.h"
#include <GLUT/glut.h>

GameBoundary::GameBoundary(double x, double y, double width, double height)
        : BoundingBox(x, y, width, height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    xyIsCenter = false;
}

void GameBoundary::draw() {
    glPushMatrix();

    glTranslated(x, y, 0);
    glBegin(GL_QUADS);

    glBegin(GL_QUADS);
    glColor3d(0.5, 0.5, 0.9);
    glVertex2d(0, 0);
    glVertex2d(width, 0);
    glVertex2d(width, height);
    glVertex2d(0, height);
    glEnd();

    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        glTranslated(width / 2, i * height / 10, 0);
        glColor3d(0, 1, 0.5);
        GLUquadric *quad = gluNewQuadric();
        gluDisk(quad, 5, 10, 10, 10);
        glPopMatrix();
    }

    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        glTranslated(i * width / 10, height / 2, 0);
        glColor3d(0, 1, 0.5);
        GLUquadric *quad = gluNewQuadric();
        gluDisk(quad, 5, 10, 10, 10);
        glPopMatrix();
    }

    glPopMatrix();
}
