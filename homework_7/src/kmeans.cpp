#include "homework_7.h"
#include "opencv2/core.hpp"

using namespace cv;
namespace ipb {
cv::Mat kMeans(const std::vector<Mat> &descriptors, int k, int max_iter) {
    Mat centers;
    Mat labels;

    Mat stacked_des;

    if (descriptors.empty()) {
        std::cerr << "matrices cannot found!!" << std::endl;
    } else {
        vconcat(descriptors, stacked_des);
        centers = Mat(k, stacked_des.cols, stacked_des.type());
        kmeans(stacked_des, k, labels,
               TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, max_iter, 1.0), 2,
               // KMEANS_PP_CENTERS, centers);
               cv::KMEANS_RANDOM_CENTERS, centers);
    }

    return centers;
}
}  // namespace ipb