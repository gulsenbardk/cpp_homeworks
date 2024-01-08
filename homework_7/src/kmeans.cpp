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
        // std::cout << centers.size() << std::endl;
        vconcat(descriptors, stacked_des);
        centers = Mat(k, stacked_des.cols, stacked_des.type());
        kmeans(stacked_des, k, labels,
               TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, max_iter, 1.0),
               2,  //! TODO termcriterialari ogrenirsin
               // KMEANS_PP_CENTERS, centers);
               cv::KMEANS_RANDOM_CENTERS, centers);
        // std::cout << centers.size() << std::endl;
    }
    //  size_t size = descriptors.size();
    //  cv::Mat vout;
    //  for (const auto& descriptor : descriptors) {
    //     cv::vconcat(descriptor, vout);
    // }

    // cv::Mat matArray[] = {descriptors[0], descriptors[1], descriptors[2]};
    // cv::Mat out;
    // cv::vconcat(matArray, 3, out);
    // std::cout << vout.size() << std::endl;
    // cv::vconcat(descriptors, 10, out);

    // Mat concatenate_descriptors;
    // vconcat(descriptors, concatenate_descriptors);
    //  for (const cv::Mat& descriptor : descriptors) {
    //      concatenate_descriptors.push_back(descriptor);
    //  }
    //   std::cout << concatenate_descriptors.size() << std::endl;
    //    if (descriptors.empty()) {
    //        std::cerr << "matrices cannot found!!" << std::endl;
    //    } else {
    //        for (const cv::Mat& descriptor : descriptors) {
    //            if (descriptor.empty()) {
    //                std::cerr << "matrix cannot found" << std::endl;
    //            } else {
    //                std::cout << "its okay" << std::endl;
    //                concatenate_descriptors.push_back(descriptor);
    //            }
    //        }
    //        // std::cout << concatenate_descriptors.size() << std::endl;
    //        //  vconcat(descriptors, concatenate_descriptors);
    //        //   kmeans(data_mat, k, labels, TermCriteria(max_iter, 10, 1.0), 3,
    //        KMEANS_PP_CENTERS,
    //        //   centers);
    //    }

    return centers;
}
}  // namespace ipb