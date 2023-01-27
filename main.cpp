
#include "tgaimage.h"

const TGAColor white = TGAColor{255, 255, 255, 255};
const TGAColor black = TGAColor{0, 0, 0, 255};
const TGAColor red = TGAColor{0, 0, 255, 255};
const TGAColor green = TGAColor{0, 255, 0, 255};
const TGAColor blue = TGAColor{255, 0, 0, 255};

// Bresenham's line algorithm
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {  // if line is steep, transpose so y is increment
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {  // make it left-to-right
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    for (float x = x0; x <= x1; x++) {          // increment x0 until it reaches x1
        float t = (x - x0) / (float)(x1 - x0);  // current x difference ratio
        int y = y0 * (1.f - t) + y1 * t;        // use difference ratio to calculate point between y0 & y1
        if (steep) {
            image.set(y, x, color);  // if transposed, de-transpose
        } else {
            image.set(x, y, color);
        }
    }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);

    // fill background
    // for (int i = 0; i < image.width(); i++) {
    //     for (int j = 0; j < image.height(); j++) {
    //         image.set(i, j, white);
    //     }
    // }

    for (int i{0}; i <= 1000000; i++) {      // for better profiling info
        line(13, 20, 80, 40, image, white);  // good
        line(20, 13, 40, 80, image, red);    // no holes!
        line(80, 40, 13, 20, image, blue);   // appears and covers first line!
    }
    image.write_tga_file("output.tga");
    return 0;
}
