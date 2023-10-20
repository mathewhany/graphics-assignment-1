//
// Created by Mathew Hany on 15/10/2023.
//

#ifndef GRAPHICS_COLOR_H
#define GRAPHICS_COLOR_H


class Color {
private:
    double red;
    double green;
    double blue;
public:
    Color(double red, double green, double blue);

    void apply();
};


#endif //GRAPHICS_COLOR_H
