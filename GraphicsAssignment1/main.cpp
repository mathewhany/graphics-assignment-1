#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>
#include "Player.h"
#include "Game.h"

Game *game;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    game->draw();
    glFlush();
}

void SpecialKey(int key, int mouseX, int mouseY) {
    game->onKeyPressed(key, mouseX, mouseY);
    glutPostRedisplay();
}

void Timer(int value) {
    game->onTimer(value);
    glutPostRedisplay();
    glutTimerFunc(1000, Timer, 0);
}

void Idle() {
    game->onIdle();
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int mouseX, int mouseY) {
    game->onKeyPressed(key, mouseX, mouseY);
}

int main(int argc, char **argv) {
    game = new Game();

    glutInit(&argc, argv);
    glutInitWindowSize(game->windowWidth, game->windowHeight);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("texture");
    glutDisplayFunc(Display);
    glutSpecialFunc(SpecialKey);
    glutKeyboardFunc(Keyboard);
    glutIdleFunc(Idle);
    glutTimerFunc(1000, Timer, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    gluOrtho2D(0, game->windowWidth, 0, game->windowHeight);
    glutMainLoop();

    return 0;
}
