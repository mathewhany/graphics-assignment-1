//
// Created by Mathew Hany on 15/10/2023.
//

#include "Scene.h"

Scene::Scene(Game *game) : game(game) {}

void Scene::draw() {
    for (auto &gameObject: gameObjects) {
        if (gameObject != nullptr) {
            gameObject->draw();
        }
    }
}

void Scene::removeObject(GameObject *obj) {
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects[i] == obj) {
            gameObjects[i] = gameObjects.back();
            gameObjects.pop_back();
            break;
        }
    }
}

void Scene::onCollision(GameObject *obj1, GameObject *obj2) {
}

void Scene::onKeyPressed(int key, int mouseX, int mouseY) {
}

void Scene::onTimer(int i) {

}

void Scene::animate() {
    for (auto &gameObject: gameObjects) {
        gameObject->animate();
    }
}

