#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <vector>

#include "homework_6.h"
using namespace std;

namespace igg {
Image::Image(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    data_.resize(rows * cols, 0);
}
int Image::rows() const {
    cout << rows_ << endl;
    return Image::rows_;
}

int Image::cols() const {
    cout << cols_ << endl;
    return Image::cols_;
}

int Image::at(const int& rows, const int& cols) const {
    return int(Image::data_.at(rows * Image::cols_ + cols));
}

uint8_t& Image::at(const int& rows, const int& cols) {
    return Image::data_.at(rows * Image::cols_ + cols);
}
bool Image::FillFromPgm(const string& file) {
    Image::img = igg::io_tools::ReadFromPgm(file);
    Image::rows_ = img.rows, Image::cols_ = img.cols;
    Image::max_val = img.max_val, Image::data_ = img.data;
    return true;
}

void Image::WriteToPgm(const string& file) {
    img.cols = Image::cols_, img.rows = Image::rows_;
    img.data = Image::data_, img.max_val = Image::max_val;
    igg::io_tools::WriteToPgm(img, file);
}

vector<float> Image::ComputeHistogram(int bins) const {
    vector<float> hist;
    hist.resize(bins, 0);
    float norm = 1.00F / (float)(Image::cols_ * Image::rows_);
    for (const auto& intensity : Image::data_) {
        int ind = int(intensity) / ((Image::max_val / bins) + 1);
        hist.at(ind) = hist.at(ind) + norm;
    }
    return hist;
};

void Image::DownScale(int scale) {
    int Row = Image::rows_ / scale;
    int Col = Image::cols_ / scale;
    vector<uint8_t> imgGray;
    imgGray.resize(Row * Col, 0);

    double posX = NAN;
    double posY = NAN;

    for (int height = 0; height < Row; height++) {
        for (int witdh = 0; witdh < Col; witdh++) {
            posX = floor(witdh * scale);
            posY = floor(height * scale);
            int suc = height * Col + witdh;
            int pre = posY * Image::cols_ + posX;
            imgGray.at(suc) = Image::data_.at(pre);
        }
    }
    Image::cols_ = Col;
    Image::rows_ = Row;
    Image::data_ = imgGray;
};

void Image::UpScale(int scale) {
    int Row = Image::rows_ * scale;
    int Col = Image::cols_ * scale;
    vector<uint8_t> imgGray;
    imgGray.resize(Row * Col, 0);

    double posX = NAN;
    double posY = NAN;

    for (int height = 0; height < Row; height++) {
        for (int witdh = 0; witdh < Col; witdh++) {
            posX = floor(witdh / scale);
            posY = (floor(height / scale);
            int suc = height * Col + witdh;
            int pre = posY * Image::cols_ + posX;
            imgGray.at(suc) = Image::data_.at(pre);
        }
    }
    Image::cols_ = Col;
    Image::rows_ = Row;
    Image::data_ = imgGray;
}

}  // namespace igg