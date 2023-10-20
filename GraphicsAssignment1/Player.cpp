//
// Created by Mathew Hany on 15/10/2023.
//

#include "BoundingBox.h"
#include "Player.h"
#include "Rectangle.h"
#include <iostream>
#include <GLUT/glut.h>

using namespace std;

double Player::PLAYER_WIDTH = 40;
double Player::PLAYER_HEIGHT = 40;

double Player::PLAYER_ANIMATE_ANGLE_STEP = 25;
double Player::PLAYER_ANIMATE_MOVE_STEP = 4;

Player::Player(double x, double y, PlayerState *playerState)
        : BoundingBox(x, y, PLAYER_WIDTH, PLAYER_HEIGHT),
          x(x), y(y),
          targetX(x), targetY(y),
          playerState(playerState),
          angle(0), targetAngle(0) {}

void Player::draw() {

    glPushMatrix();
    glTranslated(x, y, 0);
    glRotated(angle, 0, 0, 1);
    glTranslated(-x, -y, 0);
//    GLUquadric *quad = gluNewQuadric();
//    glTranslated(x, y, 0);
//    gluDisk(quad, 0, PLAYER_WIDTH / 2, 250, 250);
//    Rectangle(x, y, PLAYER_WIDTH, PLAYER_HEIGHT, Color(0, 0, 0)).draw();

    glTranslated(x, y, 0);
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-20, -5);
    glVertex2f(20, -5);
    glVertex2f(20, 5);
    glVertex2f(-20, 5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(-5, 5);
    glVertex2f(10, 5);
    glVertex2f(0, 30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2f(-5, -5);
    glVertex2f(10, -5);
    glVertex2f(0, -30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8, 0.25, 0);
    glLineWidth(10);
    glVertex2f(-3, -10);
    glVertex2f(-15, -10);
    glVertex2f(-3, 10);
    glVertex2f(-15, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glLineWidth(10);
    glVertex2f(-20, 5);
    glVertex2f(-20, 10);
    glVertex2f(-23, 15);
    glVertex2f(-27, 15);
    glVertex2f(-30, 10);
    glVertex2f(-30, -10);
    glVertex2f(-27, -15);
    glVertex2f(-23, -15);
    glVertex2f(-20, -10);
    glVertex2f(-20, -5);
    glEnd();

    glPopMatrix();
}

void Player::move(double dx, double dy) {
    targetX += dx;
    targetY += dy;

    centerX = x;
    centerY = y;
}

void Player::moveUp() {
    move(0, playerState->getSpeed());
    targetAngle = 90;
}

void Player::moveDown() {
    move(0, -playerState->getSpeed());
    targetAngle = -90;
}

void Player::moveLeft() {
    move(-playerState->getSpeed(), 0);
    targetAngle = 180;
}

void Player::moveRight() {
    move(playerState->getSpeed(), 0);
    targetAngle = 0;
}

void Player::moveTo(double x, double y) {
    this->x = x;
    this->y = y;
    targetX = x;
    targetY = y;
    centerX = x;
    centerY = y;
}

void Player::animate() {
    if (x != targetX) {
        double diff = targetX - x;

        if (diff > 0) {
            x += PLAYER_ANIMATE_MOVE_STEP;
            diff -= PLAYER_ANIMATE_MOVE_STEP;
            if (diff < 0) {
                x = targetX;
            }
        } else {
            x -= PLAYER_ANIMATE_MOVE_STEP;
            diff += PLAYER_ANIMATE_MOVE_STEP;
            if (diff > 0) {
                x = targetX;
            }
        }
    }

    if (y != targetY) {
        double diff = targetY - y;

        if (diff > 0) {
            y += PLAYER_ANIMATE_MOVE_STEP;
            diff -= PLAYER_ANIMATE_MOVE_STEP;
            if (diff < 0) {
                y = targetY;
            }
        } else {
            y -= PLAYER_ANIMATE_MOVE_STEP;
            diff += PLAYER_ANIMATE_MOVE_STEP;
            if (diff > 0) {
                y = targetY;
            }
        }
    }

    if (angle != targetAngle) {
        double diff = targetAngle - angle;

        if (diff > 180) {
            diff -= 360;
        } else if (diff < -180) {
            diff += 360;
        }

        if (diff > 0) {
            angle += PLAYER_ANIMATE_ANGLE_STEP;
            diff -= PLAYER_ANIMATE_ANGLE_STEP;
            if (diff < 0) {
                angle = targetAngle;
            }
        } else {
            angle -= PLAYER_ANIMATE_ANGLE_STEP;
            diff += PLAYER_ANIMATE_ANGLE_STEP;
            if (diff > 0) {
                angle = targetAngle;
            }
        }
    }
}

