//
// Created by Mathew Hany on 15/10/2023.
//

#include "SpeedUp.h"
#include "Color.h"
#include "Rectangle.h"
#include "Player.h"

double SpeedUp::SPEED_UP_WIDTH = 25;
double SpeedUp::SPEED_UP_HEIGHT = 25;

SpeedUp::SpeedUp(double x, double y, double duration)
        : BoundingBox(x, y, SPEED_UP_WIDTH, SPEED_UP_HEIGHT),
          x(x), y(y),
          PowerUp(duration) {
    animateInPlace = new AnimateInPlace(0.1, &animScale, 0.01);
}

void SpeedUp::draw() {
    glPushMatrix();
    glTranslated(x, y, 0);

    glScaled(1 + animScale, 1 + animScale, 1);
    glColor3d(0.8, 0.8, 1);
    gluDisk(gluNewQuadric(), 0, SPEED_UP_WIDTH - 10, 10, 5);

    glColor3d(0.1, 0.1, 0.1);
    gluDisk(gluNewQuadric(), SPEED_UP_WIDTH - 7, SPEED_UP_WIDTH - 5, 10, 5);

    glColor3d(0.9, 0.9, 0.9);
    gluDisk(gluNewQuadric(), 0, 10, 250, 250);

    glBegin(GL_TRIANGLES);
    glColor3d(0.8, 0.4, 0.1);
    glVertex2d(-SPEED_UP_WIDTH / 2, SPEED_UP_WIDTH / 2 + 10);
    glVertex2d(0, SPEED_UP_WIDTH / 2);
    glVertex2d(SPEED_UP_WIDTH / 2, SPEED_UP_WIDTH / 2 + 10);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3d(0.8, 0.4, 0.1);
    glVertex2d(8, 8);
    glVertex2d(-5, 0);
    glVertex2d(5, 0);
    glVertex2d(-8, -8);
    glEnd();

    glPopMatrix();
}

void SpeedUp::activate(PlayerState *playerState) {
    PowerUp::activate(playerState);
    playerState->setSpeed(playerState->getSpeed() + 7);
}

void SpeedUp::deactivate(PlayerState *playerState) {
    playerState->setSpeed(playerState->getSpeed() - 7);
}

std::string SpeedUp::textMessage() {
    return "Speed Up";
}

void SpeedUp::animate() {
    animateInPlace->animate();
}