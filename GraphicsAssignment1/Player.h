#ifndef GRAPHICS_PLAYER_H
#define GRAPHICS_PLAYER_H

#include "BoundingBox.h"

#include "GameObject.h"
#include "PlayerState.h"

class Player : public GameObject, public BoundingBox {
    double x;
    double y;
    PlayerState *playerState;
    double angle;
    double targetAngle;
    double targetX;
    double targetY;

public:
    static double PLAYER_WIDTH;
    static double PLAYER_HEIGHT;
    static double PLAYER_ANIMATE_ANGLE_STEP;
    static double PLAYER_ANIMATE_MOVE_STEP;

    Player(double x, double y, PlayerState *playerState);

    void draw() override;

    void animate() override;

    void move(double dx, double dy);

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void moveTo(double x, double y);
};


#endif //GRAPHICS_PLAYER_H
