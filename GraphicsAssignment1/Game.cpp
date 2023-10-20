//
// Created by Mathew Hany on 15/10/2023.
//

#include <iostream>
#include "Game.h"
#include <GLUT/glut.h>
#include "Shield.h"
#include "PowerUpsPane.h"
#include "GameOverScene.h"
#include "GameTimePane.h"
#include "GameScene.h"
#include "InstructionsScene.h"
#include "ObjectWithDuration.h"

Game::Game() {
    srand(time(nullptr));

    music.openFromFile("theme.ogg");
    music.play();
    
    windowWidth = 600;
    windowHeight = 600;
    numObstacles = 5;
    numCollectables = 5;
    numShields = 3;
    numSpeedUps = 2;
    initialPlayerLives = 5;
    powerUpDuration = 3000;
    initialPlayerSpeed = 10;
    gameTimeout = 60;

    this->playerState = new PlayerState(0, this->initialPlayerLives, 0, this->initialPlayerSpeed);

    this->playerState->addListener(this);

    this->scene = dynamic_cast<Scene *>(new InstructionsScene(this));
}

void Game::draw() {
    scene->draw();
}

bool Game::isOutOfBounds(BoundingBox &box) const {
    double startX = box.getStartX();
    double startY = box.getStartY();
    double endX = box.getEndX();
    double endY = box.getEndY();

    return startX < 0 || startY < 0 || endX > this->windowWidth || endY > this->windowHeight;
}

void Game::onKeyPressed(int key, int mouseX, int mouseY) {
    scene->onKeyPressed(key, mouseX, mouseY);
}

void Game::onTimer(int value) {
    scene->onTimer(value);
}

void Game::onPlayerStateChanged(PlayerState *state) {
    if (state->getLives() == 0) {
        scene = dynamic_cast<Scene *>(new GameOverScene(this));
    }
}

void Game::onIdle() {
    scene->animate();

    for (auto &obj1: scene->gameObjects) {
        for (auto &obj2: scene->gameObjects) {
            if (obj1 == obj2) {
                continue;
            }

            auto *box1 = dynamic_cast<BoundingBox *>(obj1);
            auto *box2 = dynamic_cast<BoundingBox *>(obj2);

            if (box1 == nullptr || box2 == nullptr) {
                continue;
            }

            if (box1->isColliding(*box2)) {
                scene->onCollision(obj1, obj2);
            }
        }

        if (dynamic_cast<ObjectWithDuration *>(obj1) != nullptr) {
            auto *obj = dynamic_cast<ObjectWithDuration *>(obj1);

            if (obj->isExpired()) {
                scene->removeObject(obj1);
            }
        }
    }
}
