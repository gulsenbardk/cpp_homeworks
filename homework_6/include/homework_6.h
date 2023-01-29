#pragma once
// #include "image.hpp"
#include <iostream>
#include <vector>

// #include "homework_6.h"
#include "io_tools.hpp"

using namespace std;
namespace igg {
class Image {
    igg::io_tools::ImageData img;
    int rows_ = 0;
    int cols_ = 0;
    uint8_t max_val = 0;
    vector<uint8_t> data_;

public:
    Image() {
        // rows_;
        // cols_;
        data_.assign(rows_ * cols_, 0);
    }
    Image(int rows, int cols);
    int rows() const;
    int cols() const;
    int at(const int& rows, const int& cols) const;  // int at(const int& rows, const int& cols);
    uint8_t& at(const int& rows, const int& cols);
    // uint8_t& at(const int& rows, const int& cols) const;

    bool FillFromPgm(const string& file);

    void WriteToPgm(const string& file);

    vector<float> ComputeHistogram(int bins) const;

    void DownScale(int scale);
    void UpScale(int scale);
};

}  // namespace igg