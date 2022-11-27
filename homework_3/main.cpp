#include <iostream>

#include "homework_3.h"

int main() {
    const std::string title = "Image Browser";
    const std::string stylesheet = "style.css";
    const image_browser::ScoredImage img1{"data/000000.png", 0.98};
    const image_browser::ScoredImage img2{"data/000100.png", 0.96};
    const image_browser::ScoredImage img3{"data/000200.png", 0.88};
    const image_browser::ScoredImage img4{"data/000300.png", 0.87};
    const image_browser::ScoredImage img5{"data/000400.png", 0.80};

    const image_browser::ScoredImage img6{"data/000500.png", 0.79};
    const image_browser::ScoredImage img7{"data/000600.png", 0.76};
    const image_browser::ScoredImage img8{"data/000700.png", 0.75};
    const image_browser::ScoredImage img9{"data/000800.png", 0.20};

    const image_browser::ImageRow triad_1{img1, img2, img3};
    const image_browser::ImageRow triad_2{img4, img5, img6};
    const image_browser::ImageRow triad_3{img7, img8, img9};

    std::vector<image_browser::ImageRow> triad = {triad_1, triad_2, triad_3};
    image_browser::CreateImageBrowser(title, stylesheet, triad);
    return 0;
}