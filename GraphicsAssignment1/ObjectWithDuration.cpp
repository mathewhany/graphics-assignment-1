//
// Created by Mathew Hany on 20/10/2023.
//

#include "ObjectWithDuration.h"
#include <GLUT/glut.h>
#include <cstdlib>

ObjectWithDuration::ObjectWithDuration(double duration) : duration(duration) {
    startTime = glutGet(GLUT_ELAPSED_TIME);
}

bool ObjectWithDuration::isExpired() {
    return glutGet(GLUT_ELAPSED_TIME) - startTime > duration;
}

ObjectWithDuration::ObjectWithDuration() {
    startTime = glutGet(GLUT_ELAPSED_TIME);
    duration = (rand() + 3000) % 3000;
}
