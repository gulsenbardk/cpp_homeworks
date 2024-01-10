#include <numeric>
#include <utility>

#include "homework_7.h"

using namespace cv;
using namespace std;

namespace ipb {
// BowDictionary *BowDictionary::bow_ = nullptr;
// BowDictionary *BowDictionary::GetInstance(const BowDictionary &instance) {
//     if (bow_ == nullptr) {
//         bow_ = new BowDictionary(instance);
//     }
//     return bow_;
// }
///////////////////////////////////////////////////////////////////////////////////
int BowDictionary::max_iterations() const { return max_iter_num; }

int BowDictionary::size() const { return size_num; }

std::vector<cv::Mat> BowDictionary::descriptors() const { return in_descriptors; }
///////////////////////////////////////////////////////////////////////////////////
int BowDictionary::total_features() {
    int total_features = 0;
    std::vector<int> count_feature;
    count_feature.reserve(in_descriptors.size());
    for (auto &in_descriptor : in_descriptors) {
        count_feature.push_back(in_descriptor.rows);
    }
    total_features = std::accumulate(count_feature.begin(), count_feature.end(), 0);
    return total_features;
}

///////////////////////////////////////////////////////////////////////////////////
void BowDictionary::set_max_iterations(int max_iterations_update) {
    this->max_iter_num = max_iterations_update;
}

void BowDictionary::set_size(int size_update) { this->size_num = size_update; }

void BowDictionary::set_descriptors(vector<Mat> descriptors_update) {
    this->in_descriptors = std::move(descriptors_update);
}

void BowDictionary::set_params(int max_iterations, int size, const vector<Mat> &descriptors) {
    this->max_iter_num = max_iterations;
    this->size_num = size;
    this->in_descriptors = descriptors;
}
///////////////////////////////////////////////////////////////////////////////////
bool BowDictionary::empty() const { return in_descriptors.empty(); }

/*void BowDictionary::set_params(int max_iterations, int size, const vector<Mat> &descriptors) {
    this->max_iter_num = max_iterations;
    this->size_num = size;
    this->in_descriptors = descriptors;
}
void BowDictionary::set_size(int size_update) { this->size_num = size_update; }
void BowDictionary::set_max_iterations(int max_iterations_update) {
    this->max_iter_num = max_iterations_update;
}
void BowDictionary::set_descriptors(vector<Mat> descriptors_update) {
    this->in_descriptors = std::move(descriptors_update);
}

bool BowDictionary::empty() const { return in_descriptors.empty(); }

int BowDictionary::max_iterations() { return max_iter_num; }
int BowDictionary::size() { return size_num; }
std::vector<cv::Mat> BowDictionary::descriptors() { return std::move(in_descriptors); }
int BowDictionary::total_features() {
    int total_features = 0;
    std::vector<int> count_feature;
    count_feature.reserve(in_descriptors.size());
    for (auto &in_descriptor : in_descriptors) {
        count_feature.push_back(in_descriptor.rows);
    }
    total_features = std::accumulate(count_feature.begin(), count_feature.end(), 0);
    return total_features;
}

*/
}  // namespace ipb
