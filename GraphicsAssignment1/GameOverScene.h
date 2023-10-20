//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GAMEOVERSCENE_H
#define GRAPHICS_GAMEOVERSCENE_H


#include "GameObject.h"

#include "Game.h"
#include "Scene.h"
#include <SFML/Audio.hpp>

class GameOverScene : public Scene {
    sf::Music music;
public:
    explicit GameOverScene(Game *game);

    void draw() override;
};


#endif //GRAPHICS_GAMEOVERSCENE_H
