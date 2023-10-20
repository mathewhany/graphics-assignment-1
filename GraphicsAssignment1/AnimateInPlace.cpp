//
// Created by Mathew Hany on 16/10/2023.
//

#include "AnimateInPlace.h"
#include "iostream"

using namespace std;

AnimateInPlace::AnimateInPlace(double maxOffset, double *value, double speed) {
    this->maxOffset = maxOffset;
    this->value = value;
    this->speed = speed;
    this->offset = 0;
}

void AnimateInPlace::animate() {
    if (this->offset > this->maxOffset || this->offset < -this->maxOffset) {
        this->speed *= -1;
    }

    this->offset += this->speed;
    *this->value += this->speed;

//    cout << *this->value << " " << this->offset << endl;
}
