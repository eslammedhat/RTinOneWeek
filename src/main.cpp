#include <iostream>
#include <string>
#include <fstream>


// constants
const std::string RENDERED_IMAGE_PATH("./");



int main() {

    // Image
    const int image_width = 256;
    const int image_height = 256;
    std::ofstream outputImage;
    outputImage.open(RENDERED_IMAGE_PATH + std::string("IMAGE.ppm"));

    // Render
    // header
    outputImage << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    // image
    for (int j = image_height-1; j >= 0; --j) {

        // progress bar for user
        std::cout << "Remaining scan lines: " << j << std::endl << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            outputImage << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    outputImage.close();
    std::cout << "\nDone.\n";
}