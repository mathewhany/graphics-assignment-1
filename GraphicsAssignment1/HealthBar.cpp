//
// Created by Mathew Hany on 15/10/2023.
//

#include <string>
#include "HealthBar.h"
#include "Color.h"
#include "Rectangle.h"
#include <GLUT/glut.h>
#include "Text.h"

double HealthBar::HEALTH_BAR_WIDTH = 200;
double HealthBar::HEALTH_BAR_HEIGHT = 30;

HealthBar::HealthBar(double x, double y, int maxHealth, PlayerState *playerState)
        : x(x), y(y), maxHealth(maxHealth), playerState(playerState) {}

void HealthBar::draw() {
    double percentage = playerState->getLives() * 1.0 / maxHealth;

    Rectangle(x, y, HEALTH_BAR_WIDTH, HEALTH_BAR_HEIGHT, Color(0.5, 0.5, 0.5), false).draw();
    Rectangle(x, y, HEALTH_BAR_WIDTH * percentage, HEALTH_BAR_HEIGHT, Color(0, 1, 0), false).draw();

    std::string healthString = std::to_string(playerState->getLives()) + "/" + std::to_string(maxHealth);

    Text(x + HEALTH_BAR_WIDTH / 2 - 20, y + 9, healthString, Color(0, 0, 0), GLUT_BITMAP_HELVETICA_18).draw();
}
