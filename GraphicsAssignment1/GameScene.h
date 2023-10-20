//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GAMESCENE_H
#define GRAPHICS_GAMESCENE_H


#include <vector>
#include "GameObject.h"
#include "Scene.h"
#include "Game.h"
#include "Player.h"
#include <SfML/audio.hpp>

class GameScene : public Scene {
    Player *player;
    
    sf::Music obstacleSound;
    sf::Music collectableSound;
    sf::Music powerUpSound;
    sf::Music goalSound;

    void loadSounds();
    
public:
    explicit GameScene(Game *game);

    std::pair<double, double> getRandomEmptyPosition(double width, double height);

    void onKeyPressed(int key, int mouseX, int mouseY) override;

    void onCollision(GameObject *obj1, GameObject *obj2) override;

    void onTimer(int value) override;

    void spawnObstacle();

    void spawnCollectable();

    void spawnShield();

    void spawnSpeedUp();

    void spawnCloud();
};


#endif //GRAPHICS_GAMESCENE_H
