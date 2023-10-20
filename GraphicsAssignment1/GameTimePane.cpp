//
// Created by Mathew Hany on 15/10/2023.
//

#include "GameTimePane.h"
#include "Text.h"

GameTimePane::GameTimePane(double x, double y) : x(x), y(y) {
    startTime = (int) (glutGet(GLUT_ELAPSED_TIME) / 1000);
}

void GameTimePane::draw() {
    std::string time = std::to_string((int) (glutGet(GLUT_ELAPSED_TIME) / 1000) - startTime);
    Text(x, y, "Time: " + time, Color(0, 0, 0), GLUT_BITMAP_HELVETICA_18).draw();
}


