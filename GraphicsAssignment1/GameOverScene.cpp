//
// Created by Mathew Hany on 15/10/2023.
//

#include "GameOverScene.h"
#include "Text.h"

GameOverScene::GameOverScene(Game *game) : Scene(game) {
    game->music.stop();
    
    music.openFromFile("defeat.ogg");
    music.play();
}

void GameOverScene::draw() {
    std::string message = "Final Score: " + std::to_string(game->playerState->getScore());
    
    Text(game->windowWidth / 2 - 70, game->windowHeight / 2, "GAME OVER!", Color(153.0 / 255.0, 0, 0), GLUT_BITMAP_TIMES_ROMAN_24).draw();
    Text(game->windowWidth / 2 - 50, game->windowHeight / 2 - 20, message, Color(153.0 / 255.0, 0, 0)).draw();
    
    glClearColor(1, 1, 1, 0);
}

