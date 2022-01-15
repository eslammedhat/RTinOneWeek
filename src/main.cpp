#include <iostream>
#include <string>
#include <fstream>

#include "ParameterHandler.hpp"
#include "Vec3.hpp"
#include "Color.hpp"
#include "Ray.hpp"

#include <memory>

// constants
const char* PROGRAM_NAME = "rt";
const char* PROGRAM_DESCRIPTION = "Ray Tracer";
//constexpr const char* PROGRAM_VERSION_MAJOR = "";
//constexpr const char* PROGRAM_VERSION_MINOR = "";
//constexpr const char* PROGRAM_VERSION_PATCH = "";



Color ray_color(const Ray& r) {
    Vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}


int main(int argc, char *argv[]) {

    ParameterHandler _ph;
    ParameterHandler::ErrorType err = _ph.parseParametrs(argc, argv);
    if (err == ParameterHandler::ErrorType::ERROR_NOK) {
        return EXIT_FAILURE;
    }
    else if (err == ParameterHandler::ErrorType::ERROR_HELP) {
        return EXIT_SUCCESS;
    }


    // Image
    const auto aspect_ratio = _ph.getImageSpectRatio();
    const auto image_width = _ph.getImageWidth();
    const auto image_height = _ph.getImageHeight();
    const auto outputImage = _ph.getOutputImage();

    //const std::shared_ptr<std::ofstream> outputImage = std::make_shared<std::ofstream>();
    //outputImage->open("" + std::string(m_outputImagePath));
    //std::ofstream *outputImage = &()

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = Point3(0, 0, 0);
    auto horizontal = Vec3(viewport_width, 0, 0);
    auto vertical = Vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focal_length);

    // Render
    // header
    *outputImage << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    // image
    for (int j = image_height - 1; j >= 0; --j) {
        std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (uint32_t i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            Color pixel_color = ray_color(r);
            color::write_color(*outputImage, pixel_color);
        }
    }

    std::cout << "\nDone.\n";
    return EXIT_SUCCESS;
}