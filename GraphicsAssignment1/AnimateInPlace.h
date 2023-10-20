//
// Created by Mathew Hany on 16/10/2023.
//

#ifndef GRAPHICS_ANIMATEINPLACE_H
#define GRAPHICS_ANIMATEINPLACE_H


class AnimateInPlace {
    double maxOffset;
    double *value;
    double speed;
    double offset;
public:
    AnimateInPlace(double maxOffset, double *value ,double speed = 0.2);

    void animate();
};


#endif //GRAPHICS_ANIMATEINPLACE_H
