//
// Created by Mathew Hany on 20/10/2023.
//

#ifndef GRAPHICS_OBJECTWITHDURATION_H
#define GRAPHICS_OBJECTWITHDURATION_H


class ObjectWithDuration {
public:
    double duration;
    double startTime;

    ObjectWithDuration(double duration);

    ObjectWithDuration();

    bool isExpired();
};


#endif //GRAPHICS_OBJECTWITHDURATION_H
