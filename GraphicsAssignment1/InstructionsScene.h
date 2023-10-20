//
// Created by Mathew Hany on 20/10/2023.
//

#ifndef GRAPHICS_INSTRUCTIONSSCENE_H
#define GRAPHICS_INSTRUCTIONSSCENE_H


#include "Scene.h"

class InstructionsScene : public Scene {
public:
    explicit InstructionsScene(Game *game);

    void draw() override;

    void onKeyPressed(int key, int mouseX, int mouseY) override;
};


#endif //GRAPHICS_INSTRUCTIONSSCENE_H
