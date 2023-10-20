//
// Created by Mathew Hany on 15/10/2023.
//

#include <string>
#include "ScoreBox.h"
#include "Text.h"
#include <iostream>

ScoreBox::ScoreBox(int x, int y, PlayerState *playerState) : x(x), y(y), playerState(playerState) {}

void ScoreBox::draw() {
    std::string scoreString = "Score: " + std::to_string(playerState->getScore());

    Text(x, y, scoreString, Color(0, 0, 0), GLUT_BITMAP_HELVETICA_18).draw();
}