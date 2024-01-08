#include "homework_7.h"
using namespace cv;
using namespace ipb::serialization;
using namespace ipb;
using namespace std;
int main() {
    std::vector<cv::Mat> load_descriptors =
        ipb::serialization::sifts::LoadDataset("../data/freiburg/bin/");
    // for (const cv::Mat& descriptor : load_descriptors) {
    //     cout << descriptor.size() << endl;
    //     cout << descriptor.type() << endl;
    //     cout << descriptor.rows << endl;
    //     cout << descriptor.cols << endl;
    // }
    // std::vector<cv::Mat> matrices_;
    // for (const cv::Mat& descriptor : load_descriptors) {
    //     matrices_.emplace_back(descriptor.rows, descriptor.cols, descriptor.type(),
    //                            descriptor.data);
    // }

    // std::vector<cv::Mat> matrices = {
    //     cv::Mat(128, 2935, CV_8UC1, cv::Scalar(1)), cv::Mat(128, 479, CV_8UC1, cv::Scalar(2)),
    //     cv::Mat(128, 513, CV_8UC1, cv::Scalar(3)),  cv::Mat(128, 240, CV_8UC1, cv::Scalar(4)),
    //     cv::Mat(128, 318, CV_8UC1, cv::Scalar(5)),  cv::Mat(128, 422, CV_8UC1, cv::Scalar(6)),
    //     cv::Mat(128, 759, CV_8UC1, cv::Scalar(7)),  cv::Mat(128, 1162, CV_8UC1, cv::Scalar(8)),
    //     cv::Mat(128, 4048, CV_8UC1, cv::Scalar(9)), cv::Mat(128, 150, CV_8UC1, cv::Scalar(10))};
    // cv::Mat out;
    // cv::hconcat(matrices, out);
    // std::cout << out.size() << std::endl;

    // Mat stacked_des;
    // vconcat(load_descriptors, stacked_des);
    // std::cout << load_descriptors.size() << std::endl;
    // for (const cv::Mat& descriptor : load_descriptors) {
    //    std::cout << descriptor.rows << std::endl;
    //}
    const int k = 10;
    const int max_iter = 10;
    cv::Mat cluster_centers = kMeans(load_descriptors, k, max_iter);  // segmentation fault
    std::cout << "Cluster Centers:\n" << cluster_centers << std::endl;

    // ipb::BowDictionary::GetInstance().set_params(max_iter, k, load_descriptors);
    //  std::cout << ipb::BowDictionary::GetInstance().empty();
    return 0;
}