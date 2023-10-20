//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_GAMEOBJECT_H
#define GRAPHICS_GAMEOBJECT_H


class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void draw() = 0;
    virtual void animate() {}
    virtual void onTimer() {}
};


#endif //GRAPHICS_GAMEOBJECT_H
