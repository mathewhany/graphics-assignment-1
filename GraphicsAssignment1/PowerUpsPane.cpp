//
// Created by Mathew Hany on 15/10/2023.
//

#include "PowerUpsPane.h"
#include <GLUT/glut.h>
#include "Text.h"
#include "Rectangle.h"

double PowerUpsPane::POWER_UP_PANE_HEIGHT = 50;
double PowerUpsPane::POWER_UP_PANE_WIDTH = 250;

PowerUpsPane::PowerUpsPane(double x, double y, std::vector<PowerUp *> *appliedPowerUps)
        : x(x),
          y(y),
          appliedPowerUps(appliedPowerUps) {}

void PowerUpsPane::draw() {
//    Rectangle(x, y, POWER_UP_PANE_WIDTH, POWER_UP_PANE_HEIGHT, Color(0, 0, 0), false).draw();

    // power ups string
    std::string powerUpsString;
    for (PowerUp *powerUp: *appliedPowerUps) {
        powerUpsString += powerUp->textMessage() + ", ";
    }

    Text(x + 5,
         y + PowerUpsPane::POWER_UP_PANE_HEIGHT - 20,
         "Power Ups: ",
         Color(0, 0, 0), GLUT_BITMAP_HELVETICA_18).draw();

    Text(x + 5,
         y + PowerUpsPane::POWER_UP_PANE_HEIGHT - 35,
         powerUpsString,
         Color(0, 0, 0), GLUT_BITMAP_HELVETICA_12).draw();
}

