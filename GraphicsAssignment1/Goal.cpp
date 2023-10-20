//
// Created by Mathew Hany on 15/10/2023.
//

#include "Goal.h"
#include "Color.h"
#include "Rectangle.h"
#include <GLUT/glut.h>
#include "Text.h"

double Goal::GOAL_WIDTH = 25;
double Goal::GOAL_HEIGHT = 60;

Goal::Goal(double x, double y) : BoundingBox(x, y, GOAL_WIDTH, GOAL_HEIGHT), x(x), y(y) {
    animateInPlace = new AnimateInPlace(0.1, &animScale, 0.005);
}

void Goal::draw() {

    glPushMatrix();

    glTranslated(x, y, 0);

    glScaled(1 + animScale, 1 + animScale, 1);

    glBegin(GL_TRIANGLES);
    glColor3i(40, 43, 114);
    glVertex2d(-GOAL_WIDTH / 2, 5);
    glVertex2d(0, GOAL_HEIGHT / 2);
    glVertex2d(GOAL_WIDTH / 2, 5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3d(0.4, 0.4, 0.4);
    glVertex2d(GOAL_WIDTH / 2, 5);
    glVertex2d(GOAL_WIDTH / 2 - 2, -GOAL_HEIGHT);
    glVertex2d(-GOAL_WIDTH / 2 + 2, -GOAL_HEIGHT);
    glVertex2d(-GOAL_WIDTH / 2, 5);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(1, 1, 1);
    glVertex2d(0, -60);
    glVertex2d(0, -54);
    glVertex2d(0, -51);
    glVertex2d(0, -41);
    glVertex2d(0, -38);
    glVertex2d(0, -28);
    glVertex2d(0, -25);
    glVertex2d(0, -15);
    glVertex2d(0, -12);
    glVertex2d(0, -2);
    glVertex2d(0, 1);
    glVertex2d(0, 10);
    glEnd();

    glPushMatrix();
    glTranslated(0, -GOAL_HEIGHT / 2 + 3, 0);
    glColor3d(0.9, 0.9, 0.9);
    gluDisk(gluNewQuadric(), 0, 7, 250, 250);
    glPopMatrix();

    Text(
    -10, 35, "END",
            Color(0.5, 0.5 , 0.5),
            GLUT_BITMAP_TIMES_ROMAN_10
    ).draw();

    // draw X
    glPushMatrix();
    glTranslated(GOAL_WIDTH / 2 - 12, -GOAL_HEIGHT / 2 + 3, 0);
    glPushMatrix();
    glRotated(45, 0, 0, 1);
    Rectangle(0, 0, 10, 3, Color(0, 0.7, 0)).draw();
    glPopMatrix();

    glPushMatrix();
    glRotated(-45, 0, 0, 1);
    Rectangle(0, 0, 10, 3, Color(0, 0.7, 0)).draw();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void Goal::animate() {
    animateInPlace->animate();
}
