#include <iostream>
#include <cmath>
#include <fstream>

#include "color.h"
#include "vec3.h"
#include "ray.h"

color ray_color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}


int main() {

    // Imaged

    std::ofstream file;
    file.open("image.ppm");

    const int image_width = 256;
    const int image_height = 256;

    // Render

    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::cerr << "\rScanlines remaining: " << image_height - 1 - j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / image_width;
            auto b = double(j) / image_height;

            auto g = 0;

            color pixel_color(r, g, b);
            write_color(file, pixel_color);
        }
    }

    file.close();

    std::cerr << "\nDone.\n";
}