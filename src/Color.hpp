#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

#include "Vec3.hpp"

using Color = Vec3;    // RGB color

namespace color{

    void write_color(std::ostream & out, Color pixel_color);

}

#endif