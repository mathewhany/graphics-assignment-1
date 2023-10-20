//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GAME_H
#define GRAPHICS_GAME_H


#include <vector>
#include "PlayerState.h"
#include "Scene.h"
#include "BoundingBox.h"
#include <SFML/Audio.hpp>

class Scene;

class Game : public PlayerStateListener {    
public:
    sf::Music music;

    double windowWidth;
    double windowHeight;
    int numCollectables;
    int numShields;
    int numObstacles;
    int numSpeedUps;
    int powerUpDuration;
    int initialPlayerLives;
    double initialPlayerSpeed;
    int gameTimeout;

    PlayerState *playerState;

    Scene *scene;

    Game();

    void draw();

    void onKeyPressed(int key, int mouseX, int mouseY);

    void onTimer(int value);

    bool isOutOfBounds(BoundingBox &box) const;

    void onPlayerStateChanged(PlayerState *state) override;

    void onIdle();
};


#endif //GRAPHICS_GAME_H
