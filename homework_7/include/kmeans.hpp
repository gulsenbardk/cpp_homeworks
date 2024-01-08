#include <filesystem>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter);
}  // namespace ipb