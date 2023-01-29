#include <filesystem>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "homework_5.h"

using namespace cv;
using namespace std;

using cv::SiftDescriptorExtractor;
using cv::SiftFeatureDetector;

int main() {
    const std::string lenna_path = "../data/lenna.png";
    const std::string lenna_bin_path = "../data/lenna.bin";
    const std::string des_bin_path = "../data/des.bin";
    auto m = cv::imread(lenna_path, IMREAD_ANYCOLOR);
    ipb::serialization::Serialize(m, lenna_bin_path);
    ipb::serialization::Deserialize(lenna_bin_path);

    const std::string test_path = {"../data/freiburg/images/"};
    ipb::serialization::sifts::ConvertDataset(test_path);
    const std::string test_bin_path = {"../data/freiburg/bin/"};
    ipb::serialization::sifts::LoadDataset(test_bin_path);
    return 0;
}
