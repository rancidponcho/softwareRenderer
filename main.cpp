
#include "tgaimage.h"

const TGAColor white = TGAColor{255, 255, 255, 255};
const TGAColor black = TGAColor{0, 0, 0, 255};
const TGAColor red = TGAColor{0, 0, 255, 255};
const TGAColor green = TGAColor{0, 255, 0, 255};
const TGAColor blue = TGAColor{255, 0, 0, 255};

// Bresenham's line algorithm
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    for (float x = x0; x <= x1; x++) {          // increment x0 until it reaches x1
        float t = (x - x0) / (float)(x1 - x0);  // current x difference ratio
        int y = y0 * (1.f - t) + y1 * t;        // use difference ratio to calculate point between y0 & y1
        image.set(x, y, color);
    }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);

    // fill background
    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            image.set(i, j, white);
        }
    }

    line(13, 20, 80, 40, image, black);  // good
    line(20, 13, 40, 80, image, red);    // holes
    line(80, 40, 13, 20, image, blue);   // doesnt show

    image.write_tga_file("output.tga");
    return 0;
}
