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

#include "homework_5.h"

using cv::SiftDescriptorExtractor;
using cv::SiftFeatureDetector;
using namespace cv;
using namespace std;

namespace ipb::serialization::sifts {
void ConvertDataset(const filesystem::path& img_path) {
    const filesystem::path bin = img_path.parent_path().replace_filename("bin/");
    filesystem::create_directory(bin);
    const string bin_path = bin.string();

    for (const auto& img : filesystem::directory_iterator(img_path))
        if (filesystem::path(img).extension() != ".png") {
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

std::vector<cv::Mat> LoadDataset(const filesystem::path& bin_path) {
    vector<cv::Mat> SIFT_Features;
    if (!bin_path.empty()) {
        EXIT_FAILURE;
    } else {
        for (const auto& bin : filesystem::directory_iterator(bin_path))
            if (filesystem::path(bin).extension() != ".bin") {
                EXIT_FAILURE;
            } else {
                string bin_file = bin.path().string();
                Mat descriptors = ipb::serialization::Deserialize(bin_file);
                SIFT_Features.push_back(descriptors);
            }
    }
    return SIFT_Features;
}

}  // namespace ipb::serialization::sifts