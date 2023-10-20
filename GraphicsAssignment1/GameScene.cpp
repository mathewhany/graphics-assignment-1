//
// Created by Mathew Hany on 15/10/2023.
//

#include <iostream>
#include "GameScene.h"
#include "Player.h"
#include "Game.h"
#include "PowerUpsPane.h"
#include "GameTimePane.h"
#include "WonScene.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Collectable.h"
#include "Shield.h"
#include "SpeedUp.h"
#include "ScoreBox.h"
#include "HealthBar.h"
#include "GameOverScene.h"
#include "GameBoundary.h"
#include "Clouds.h"

#define TOP_PANEL_HEIGHT 50

GameScene::GameScene(Game *game) : Scene(game) {
    // init game bounds
    auto *topBound = new GameBoundary(0, game->windowHeight - TOP_PANEL_HEIGHT - 20, game->windowWidth, 20);
    auto *bottomBound = new GameBoundary(0, 0, game->windowWidth, 20);
    auto *rightBound = new GameBoundary(0, 0, 20, game->windowHeight - TOP_PANEL_HEIGHT);
    auto *leftBound = new GameBoundary(game->windowWidth - 20, 0, 20, game->windowHeight - TOP_PANEL_HEIGHT);

    gameObjects.push_back(topBound);
    gameObjects.push_back(bottomBound);
    gameObjects.push_back(rightBound);
    gameObjects.push_back(leftBound);

    // init clouds
    for (int i = 0; i < 2; i++) {
        spawnCloud();
    }

    // init player
    player = new Player(game->windowWidth / 2, game->windowHeight / 2, game->playerState);
    gameObjects.push_back(player);

    // init goal
    Goal *goal = new Goal(25 + Goal::GOAL_WIDTH, 25 + Goal::GOAL_HEIGHT);
    gameObjects.push_back(goal);


    // init obstacles
    for (int i = 0; i < game->numObstacles; i++) {
        spawnObstacle();
    }

    // init collectables
    for (int i = 0; i < game->numCollectables; i++) {
        spawnCollectable();
    }

    // init shields
    for (int i = 0; i < game->numShields; i++) {
        spawnShield();
    }

    // init speed ups
    for (int i = 0; i < game->numSpeedUps; i++) {
        spawnSpeedUp();
    }

    // init power ups pane
    auto *powerUpsPane = new PowerUpsPane(game->windowWidth - PowerUpsPane::POWER_UP_PANE_WIDTH,
                                          game->windowHeight - PowerUpsPane::POWER_UP_PANE_HEIGHT - 5,
                                          &game->playerState->appliedPowerUps);
    this->gameObjects.push_back(powerUpsPane);

    // init timer
    auto *gameTime = new GameTimePane(game->windowWidth - 90, game->windowHeight - 25);
    this->gameObjects.push_back(gameTime);


    // init score board
    auto *scoreBox = new ScoreBox(250, game->windowHeight - 25, game->playerState);
    gameObjects.push_back(scoreBox);

    // init health bar
    auto *healthBar = new HealthBar(10, game->windowHeight - HealthBar::HEALTH_BAR_HEIGHT - 10,
                                    game->initialPlayerLives,
                                    game->playerState);
    gameObjects.push_back(healthBar);

    glClearColor(175.0 / 255, 202.0 / 255, 255.0 / 255, 0);
    
    loadSounds();    
}

void GameScene::spawnCloud() {
    auto *cloud = new Clouds(
            -100,
            rand() % (int) (game->windowHeight - TOP_PANEL_HEIGHT),
            ((rand() % 150) + 50) / 100.0
    );
    gameObjects.push_back(cloud);
}

void GameScene::spawnSpeedUp() {
    std::pair<double, double> position = getRandomEmptyPosition(
            SpeedUp::SPEED_UP_WIDTH,
            SpeedUp::SPEED_UP_HEIGHT);
    auto *speedUp = new SpeedUp(position.first, position.second, game->powerUpDuration);
    gameObjects.push_back(speedUp);
}

void GameScene::spawnShield() {
    std::pair<double, double> position = getRandomEmptyPosition(
            Shield::SHIELD_WIDTH,
            Shield::SHIELD_HEIGHT);
    auto *shield = new Shield(position.first, position.second, game->powerUpDuration);
    gameObjects.push_back(shield);
}

void GameScene::spawnCollectable() {
    std::pair<double, double> position = getRandomEmptyPosition(
            Collectable::COLLECTABLE_WIDTH,
            Collectable::COLLECTABLE_HEIGHT);
    auto *collectable = new Collectable(position.first, position.second);
    gameObjects.push_back(collectable);
}

void GameScene::spawnObstacle() {
    std::pair<double, double> position = getRandomEmptyPosition(
            Obstacle::OBSTACLE_WIDTH,
            Obstacle::OBSTACLE_HEIGHT);
    auto *obstacle = new Obstacle(position.first, position.second);
    gameObjects.push_back(obstacle);
}

std::pair<double, double> GameScene::getRandomEmptyPosition(double width, double height) {
    while (true) {
        double x = rand() % (int) game->windowWidth;
        double y = rand() % (int) game->windowHeight;

        BoundingBox box(x, y, width, height);

        if (game->isOutOfBounds(box)) continue;

        if (box.getStartY() > game->windowHeight - TOP_PANEL_HEIGHT) continue;

        bool isColliding = false;
        for (auto &gameObject: gameObjects) {
            auto *otherBox = dynamic_cast<BoundingBox *>(gameObject);

            if (otherBox == nullptr) continue;

            if (otherBox->isColliding(box)) {
                isColliding = true;
                break;
            }
        }

        if (isColliding) continue;

        return std::make_pair(x, y);
    }
}

void GameScene::onCollision(GameObject *obj1, GameObject *obj2) {
    Player *player;
    GameObject *box;

    if (dynamic_cast<Player *>(obj1) != nullptr) {
        player = dynamic_cast<Player *>(obj1);
        box = obj2;
    } else if (dynamic_cast<Player *>(obj2) != nullptr) {
        player = dynamic_cast<Player *>(obj2);
        box = obj1;
    } else {
        return;
    }

    if (dynamic_cast<Obstacle *>(box) != nullptr || dynamic_cast<GameBoundary *>(box) != nullptr) {
        if (obstacleSound.getStatus() != sf::Sound::Playing) {
            obstacleSound.play();
        }
        player->moveTo(game->windowWidth / 2, game->windowHeight / 2);

        if (game->playerState->getShields() > 0) {
//            removeObject(box);
            game->playerState->setShields(game->playerState->getShields() - 1);
            game->playerState->removeShield();
            return;
        } else {
            game->playerState->decrementLives();
        }
        return;
    }

    if (dynamic_cast<Collectable *>(box) != nullptr) {
        if (collectableSound.getStatus() != sf::Sound::Playing) {
            collectableSound.play();
        }
        game->playerState->incrementScore();
        removeObject(box);
        return;
    }

    if (dynamic_cast<PowerUp *>(box) != nullptr) {
        if (powerUpSound.getStatus() != sf::Sound::Playing) {
            powerUpSound.play();
        }
        auto *powerUp = dynamic_cast<PowerUp *>(box);
        powerUp->activate(game->playerState);
        removeObject(box);
        game->playerState->appliedPowerUps.push_back(powerUp);
        return;
    }

    if (dynamic_cast<Goal *>(box) != nullptr) {
        if (goalSound.getStatus() != sf::Sound::Playing) {
            goalSound.play();
        }
        game->scene = dynamic_cast<Scene *>(new WonScene(game));
        return;
    }
}

void GameScene::onKeyPressed(int key, int mouseX, int mouseY) {
    switch (key) {
        case GLUT_KEY_UP:
            player->moveUp();
            break;
        case GLUT_KEY_DOWN:
            player->moveDown();
            break;
        case GLUT_KEY_LEFT:
            player->moveLeft();
            break;
        case GLUT_KEY_RIGHT:
            player->moveRight();
            break;
        default:
            break;
    }
}

void GameScene::onTimer(int value) {
    game->playerState->removeExpiredPowerUps();

    int time = glutGet(GLUT_ELAPSED_TIME) / 1000;

    if (time > game->gameTimeout) {
        game->scene = dynamic_cast<Scene *>(new GameOverScene(game));
    }

    if (rand() % 100 > 70) {
        spawnCloud();
    }
//    if ((rand() % 100) > 80) {
//        spawnCollectable();
//    }
//    if ((rand() % 100) > 80) {
//        spawnSpeedUp();
//    }
//    if ((rand() % 100) > 80) {
//        spawnShield();
//    }
}

void GameScene::loadSounds() {
    obstacleSound.openFromFile("obstacle.wav");
    collectableSound.openFromFile("collectable.wav");
    powerUpSound.openFromFile("powerUp.wav");
    goalSound.openFromFile("goal.wav");
}
