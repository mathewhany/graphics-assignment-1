//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_WONSCENE_H
#define GRAPHICS_WONSCENE_H


#include "Game.h"
#include <SFML/Audio.hpp>

class WonScene : public Scene {
    sf::Music music;
public:
    WonScene(Game *pGame);

    void draw() override;
};


#endif //GRAPHICS_WONSCENE_H
