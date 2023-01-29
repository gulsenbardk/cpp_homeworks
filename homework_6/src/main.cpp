#include <iostream>

#include "homework_6.h"
#include "io_tools.hpp"
using namespace std;
int main() {
    // igg::Image(34, 34);
    igg::io_tools::ImageData img = igg::io_tools::ReadFromPgm("../data/lena.ascii.pgm");
    // cout << img.max_val;

    return 0;
}