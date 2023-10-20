//
// Created by Mathew Hany on 20/10/2023.
//

#include "InstructionsScene.h"
#include "GameScene.h"
#include "Text.h"
#include <GLUT/glut.h>

InstructionsScene::InstructionsScene(Game *game) : Scene(game) {}

void InstructionsScene::draw() {
    Text(game->windowWidth / 2 - 127, 10, "Press Space to start ...").draw();

    Text(0, game->windowHeight - 30, "1. Your goal is to reach the end, and collect \nas much medals as you can").draw();
    Text(0, game->windowHeight - 60, "2. Try to avoid obstacles or you will lose lives").draw();
    Text(0, game->windowHeight - 90, "3. Don't hit game boundaries or you will lose lives").draw();
    Text(0, game->windowHeight - 120, "5. Shields protect you from obstacles").draw();
    Text(0, game->windowHeight - 150, "6. Speed Ups makes you faster").draw();
    Text(0, game->windowHeight - 180, "7. You have 60 seconds to reach the goal or you lose").draw();


}

void InstructionsScene::onKeyPressed(int key, int mouseX, int mouseY) {
    if (key == ' ') {
        game->scene = dynamic_cast<Scene *>(new GameScene(game));
    }
}
