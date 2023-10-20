#include "BoundingBox.h"

BoundingBox::BoundingBox(double centerX, double centerY, double width, double height)
        : centerX(centerX),
          centerY(centerY),
          width(width),
          height(height), xyIsCenter(true) {}

bool BoundingBox::isColliding(BoundingBox &other) {
    double startX = getStartX();
    double startY = getStartY();
    double endX = getEndX();
    double endY = getEndY();

    double otherStartX = other.getStartX();
    double otherStartY = other.getStartY();
    double otherEndX = other.getEndX();
    double otherEndY = other.getEndY();

    return !(endX < otherStartX || startX > otherEndX || endY < otherStartY || startY > otherEndY);
}

double BoundingBox::getStartX() {
    if (xyIsCenter) {
        return centerX - width / 2;
    }
    return centerX;
}

double BoundingBox::getStartY() {
    if (xyIsCenter) {
        return centerY - height / 2;
    }
    return centerY;
}

double BoundingBox::getEndX() {
    if (xyIsCenter) {
        return centerX + width / 2;
    }

    return centerX + width;
}

double BoundingBox::getEndY() {
    if (xyIsCenter) {
        return centerY + height / 2;
    }
    return centerY + height;
}

