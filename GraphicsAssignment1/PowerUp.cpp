//
// Created by Mathew Hany on 15/10/2023.
//

#include "PowerUp.h"

PowerUp::PowerUp(double duration) : duration(duration) {
}

void PowerUp::activate(PlayerState *) {
    appliedAt = glutGet(GLUT_ELAPSED_TIME);
}

bool PowerUp::isExpired() {
    return glutGet(GLUT_ELAPSED_TIME) - appliedAt > duration;
}
