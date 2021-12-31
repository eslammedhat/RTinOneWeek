#include <iostream>
#include <string>
#include <fstream>


#include "Vec3.hpp"
#include "Color.hpp"

// constants
const std::string RENDERED_IMAGE_PATH("./");



int main() {
    const Vec3 ray;
    double x = ray.x();


    // Image
    const int image_width = 256;
    const int image_height = 256;
    std::ofstream outputImage;
    outputImage.open(RENDERED_IMAGE_PATH + std::string("IMAGE.ppm"));

    // Render
    // header
    outputImage << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // image
    for (int j = image_height - 1; j >= 0; --j) {
        std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
            color::write_color(outputImage, pixel_color);
        }
    }

    outputImage.close();
    std::cout << "\nDone.\n";
}