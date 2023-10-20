//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_POWERUP_H
#define GRAPHICS_POWERUP_H

#include <string>
#include <GLUT/glut.h>

class PlayerState;

class PowerUp {
public:
    double appliedAt;
    double duration;

    explicit PowerUp(double duration);

    virtual void activate(PlayerState *playerState);

    virtual void deactivate(PlayerState *playerState) = 0;

    virtual std::string textMessage() = 0;

    bool isExpired();

};

#endif //GRAPHICS_POWERUP_H
