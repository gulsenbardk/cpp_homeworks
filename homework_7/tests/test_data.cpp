// @file      test_data.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2020 Ignacio Vizzo, all rights reserved
#include "test_data.hpp"

#include <opencv2/opencv.hpp>
#include <vector>

namespace {
// type aliases
using namespace cv;
using MatVector = std::vector<Mat>;

// parameters
const int rows_num = 1;
const int cols_num = 10;

template <typename T>
T GenerateData(int max_number, int steps, int repeat_rows) {
    T data;
    for (int i = 0; i < max_number; i += steps) {
        for (int j = 0; j < repeat_rows; j++) {
            Mat_<float> vec(rows_num, cols_num, static_cast<float>(i));
            data.push_back(vec);
        }
    }

    return data;
}

Mat GenerateRows(const std::vector<float>& values) {
    Mat data;
    for (const auto& value : values) {
        data.push_back(Mat_<float>(rows_num, cols_num, value));
    }
    return data;
}
}  // namespace

MatVector GetDummyData() { return GenerateData<MatVector>(100, 20, 5); }
Mat GetAllFeatures() { return GenerateData<Mat>(100, 20, 5); }
Mat Get18Kmeans() { return GenerateData<Mat>(100, 20, 3); }
Mat Get5Kmeans() { return GenerateData<Mat>(100, 20, 1); }
Mat Get3Kmeans() { return GenerateRows({0.0F, 30.0F, 70.0F}); }
Mat Get2Kmeans() { return GenerateRows({20.000002F, 70.0F}); }
