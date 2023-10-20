//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_SCOREBOX_H
#define GRAPHICS_SCOREBOX_H



#include "GameObject.h"
#include "PlayerState.h"

class ScoreBox : public GameObject {
    int x;
    int y;
    PlayerState *playerState;
public:
    ScoreBox(int x, int y, PlayerState *playerState);

    void draw() override;
};


#endif //GRAPHICS_SCOREBOX_H
