
#include <bitset>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>
#include <tuple>
#include <vector>

#include "homework_7.h"

using cv::SiftDescriptorExtractor;
using cv::SiftFeatureDetector;
using namespace cv;
using namespace std;

namespace ipb::serialization {

void Serialize(const Mat& m, const string& filename) {
    ofstream fout(filename, ios::out | ios::binary);
    int type = m.type();
    int rows = m.rows;
    int cols = m.cols;
    auto* data = m.data;
    fout.write(reinterpret_cast<char*>(&type), sizeof(type));
    fout.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    fout.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    fout.write(reinterpret_cast<char*>(&data), sizeof(data));
    fout.close();
}

cv::Mat Deserialize(const std::string& filename) {
    int type = 0;
    int rows = 0;
    int cols = 0;
    // uchar* data = nullptr;
    ifstream fin(filename, iostream::binary);
    if (!fin) {
        EXIT_FAILURE;
    }
    fin.read(reinterpret_cast<char*>(&type), sizeof(type));
    fin.read(reinterpret_cast<char*>(&rows), sizeof(rows));
    fin.read(reinterpret_cast<char*>(&cols), sizeof(cols));
    Mat M(rows, cols, type);  //,data);
    uchar* data = M.data;

    for (int i = 0; i < rows * cols; i++) {
        fin.read(reinterpret_cast<char*>(&data[i]), sizeof(data[i]));  // hw_5>fix
    }
    // fin.read(reinterpret_cast<char*>(&data), sizeof(data)); ->data allocate

    return M;
}
}  // namespace ipb::serialization