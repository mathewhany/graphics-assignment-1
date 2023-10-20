//
// Created by Mathew Hany on 15/10/2023.
//

#include "WonScene.h"
#include "Text.h"

WonScene::WonScene(Game *pGame) : Scene(pGame) {
    game->music.stop();
    
    music.openFromFile("victory.ogg");
    music.play();
}

void WonScene::draw() {
    std::string message = "Final Score: " + std::to_string(game->playerState->getScore());
    
    Text(game->windowWidth / 2 - 70, game->windowHeight / 2, "YOU WOOON!!", Color(0, 0.5, 0), GLUT_BITMAP_TIMES_ROMAN_24).draw();
    Text(game->windowWidth / 2 - 50, game->windowHeight / 2 - 20, message, Color(0, 0.5, 0)).draw();
    
    glClearColor(1, 1, 1, 0);
}
