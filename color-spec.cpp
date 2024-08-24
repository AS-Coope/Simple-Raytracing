#include "vec3.h"
#include "color.h"
#include <iostream>


// This is the first example from Ray Tracing in One Weekend
int main ()
{
    //Image
    int image_height = 255;
    int image_width = 255;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j=0; j < image_height; ++j)
    {
        std::clog << "\rScanlines remaining: " << (image_height - 1) << ' ' << std::flush;
        for(int i=0; i < image_width; ++i)
        {
        /*
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << "\n";
        */
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1),0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rRendering complete...\n";

}
