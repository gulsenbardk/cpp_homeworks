#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>
#include <tuple>
#include <vector>

#include "homework_7.h"

using cv::SiftDescriptorExtractor;
using cv::SiftFeatureDetector;
using namespace cv;
using namespace std;

namespace ipb::serialization::sifts {
void ConvertDataset(const std::filesystem::path& img_path) {
    const std::filesystem::path bin = img_path.parent_path().replace_filename("bin/");
    std::filesystem::create_directory(bin);
    const string bin_path = bin.string();

    for (const auto& img : std::filesystem::directory_iterator(img_path)) {
        if (std::filesystem::path(img).extension() != ".png") {
            EXIT_FAILURE;
        } else {
            string image_path = img.path().string();
            auto m = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
            // string bin_path = img.path().parent_path().parent_path().string() + "/bin/";
            // std::filesystem::create_directory(bin_path);
            string path_filename = bin_path + img.path().stem().string() + ".bin";

            // SIFT
            auto detector = SiftFeatureDetector::create();
            vector<cv::KeyPoint> keypoints;
            detector->detect(m, keypoints);

            cv::Mat descriptors;
            auto extractor = SiftDescriptorExtractor::create();
            extractor->compute(m, keypoints, descriptors);

            ipb::serialization::Serialize(descriptors, path_filename);
        }
    }
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path& bin_path) {
    vector<cv::Mat> SIFT_Features;

    if (!exists(bin_path)) {
        cerr << "Path not exist." << endl;
        return SIFT_Features;
    }

    if (!is_directory(bin_path)) {
        cerr << "Path not a directory." << endl;
        return SIFT_Features;
    }

    for (const auto& bin : std::filesystem::directory_iterator(bin_path)) {
        if (bin.path().extension() != ".bin") {
            cerr << "Not a bin file " << endl;
            continue;
        }

        string bin_file = bin.path().string();
        Mat descriptors = ipb::serialization::Deserialize(bin_file);

        SIFT_Features.push_back(descriptors);
    }

    return SIFT_Features;
}

}  // namespace ipb::serialization::sifts