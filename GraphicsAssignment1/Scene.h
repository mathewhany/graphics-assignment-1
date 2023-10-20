//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include "GameObject.h"
#include <vector>

class Game;

class Scene {
protected:
    Game *game;
public:
    std::vector<GameObject *> gameObjects;
    explicit Scene(Game *game);
    virtual ~Scene() = default;

    virtual void draw();

    virtual void onKeyPressed(int key, int mouseX, int mouseY);

    virtual void onCollision(GameObject *obj1, GameObject *obj2);

    void removeObject(GameObject *obj);

    virtual void onTimer(int i);

    virtual void animate();
};


#endif //GRAPHICS_SCENE_H
