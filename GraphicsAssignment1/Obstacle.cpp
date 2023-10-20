//
// Created by Mathew Hany on 15/10/2023.
//

#include "Obstacle.h"
#include "Color.h"
#include "Rectangle.h"
#include <GLUT/glut.h>
#include "AnimateInPlace.h"

double Obstacle::OBSTACLE_WIDTH = 20;
double Obstacle::OBSTACLE_HEIGHT = 20;

Obstacle::Obstacle(double x, double y) : BoundingBox(x, y, OBSTACLE_WIDTH, OBSTACLE_HEIGHT), x(x), y(y) {
    animateInPlace = new AnimateInPlace(360, &animAngle, 1);
}

void Obstacle::draw() {
    glPushMatrix();
    glTranslated(x, y, 0);

    glRotated(animAngle, 0, 0, 1);

    for (int i = 0; i < 360 / 45; i++) {
        glPushMatrix();
        glRotated(45 * i, 0, 0, 1);
        Rectangle(0, 0, OBSTACLE_WIDTH + 3, 4, Color(1, 0, 0)).draw();
        glPopMatrix();
    }

    glPushMatrix();
    glRotated(45, 0, 0, 1);
    Rectangle(0, 0, 10, 10, Color(0, 0, 0)).draw();
    glPopMatrix();

    glPopMatrix();
}

void Obstacle::animate() {
    animateInPlace->animate();
}