//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_BOUNDINGBOX_H
#define GRAPHICS_BOUNDINGBOX_H


class BoundingBox {
public:
    double centerX;
    double centerY;
    double width;
    double height;
    bool xyIsCenter;

    virtual ~BoundingBox() = default;

    BoundingBox(double centerX, double centerY, double width, double height);

    bool isColliding(BoundingBox &other);

    double getStartX();
    double getStartY();
    double getEndX();
    double getEndY();
};


#endif //GRAPHICS_BOUNDINGBOX_H
