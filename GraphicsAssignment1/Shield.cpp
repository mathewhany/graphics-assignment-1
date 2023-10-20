//
// Created by Mathew Hany on 15/10/2023.
//

#include "Shield.h"
#include <GLUT/glut.h>
#include "PlayerState.h"

double Shield::SHIELD_WIDTH = 25;
double Shield::SHIELD_HEIGHT = 25;

Shield::Shield(double x, double y, double duration)
        : BoundingBox(x, y, SHIELD_WIDTH, SHIELD_HEIGHT),
          x(x), y(y),
          PowerUp(duration) {
    this->animateInPlace = new AnimateInPlace(5, &this->y);
}

void Shield::draw() {
    glColor3f(0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslated(x, y, 0);

    glColor3d(0.5, 0.2, 0.2);
    gluDisk(gluNewQuadric(), 0, SHIELD_WIDTH - 10, 5, 5);

    glColor3d(0.5, 0.2, 0.2);
    gluDisk(gluNewQuadric(), SHIELD_WIDTH - 7, SHIELD_WIDTH - 5, 5, 5);

    glColor3d(0.9, 0.9, 0.9);
    gluDisk(gluNewQuadric(), 0, 10, 250, 250);

    glPushMatrix();
    glTranslated(0, 0, 0);
    glBegin(GL_LINES);
    glColor3d(0.3, 0.5, 0.3);
    glVertex2d(-5, 0);
    glVertex2d(5, 0);
    glVertex2d(0, 5);
    glVertex2d(0, -5);
    glEnd();
    glPopMatrix();


    glBegin(GL_TRIANGLES);
    glColor3d(0.5, 0.2, 0.2);
    glVertex2d(0, SHIELD_WIDTH / 2 + 3);
    glVertex2d(SHIELD_WIDTH / 2, SHIELD_WIDTH / 2 + 10);
    glVertex2d(-SHIELD_WIDTH / 2, SHIELD_WIDTH / 2 + 10);
    glEnd();

    glPopMatrix();
}

void Shield::activate(PlayerState *playerState) {
    PowerUp::activate(playerState);
    playerState->setShields(playerState->getShields() + 1);
}

void Shield::deactivate(PlayerState *playerState) {
    playerState->setShields(playerState->getShields() - 1);
}

std::string Shield::textMessage() {
    return "Shield";
}

void Shield::animate() {
    animateInPlace->animate();
}