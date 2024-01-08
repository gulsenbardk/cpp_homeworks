#include "homework_7.h"
#include "kmeans.hpp"
using namespace std;
using namespace cv;
namespace ipb {
class BowDictionary {
public:
    static BowDictionary& GetInstance() {
        static BowDictionary instance;
        return instance;
    }

private:
    BowDictionary() {}  // constructor
    // BowDictionary(BowDictionary const&);
    // void operator=(BowDictionary const&);

public:
    BowDictionary(BowDictionary const&) = delete;
    void operator=(BowDictionary const&) = delete;
    // protected:
    //     BowDictionary(BowDictionary const &instance) : instance_(instance) {}
    //     //~BowDictionary();
    //     static BowDictionary *bow_;
    //     BowDictionary const &instance_;
    //
    // public:
    //     BowDictionary(BowDictionary &) = delete; // not cloneable
    //     void operator=(const BowDictionary &) = delete; //not assignable
    //     static BowDictionary *GetInstance(BowDictionary const &instance);

public:
    int max_iter_num = 0;
    int size_num = 0;
    std::vector<cv::Mat> in_descriptors;
    cv::Mat output_mat;

    ///////////////////////////////////////////////////

    int max_iterations();
    int size();  // number of centroids / codewords
    vector<Mat> descriptors();
    int total_features();  // number of input features

    ///////////////////////////////////////////////////

    void set_max_iterations(int max_iterations);
    void set_size(int size);
    void set_descriptors(vector<Mat> descriptors);
    void set_params(int max_iterations, int size, const vector<Mat>& descriptors);
    ///////////////////////////////////////////////////
    bool empty() const;
};
/*class BowDictionary {
    // private:
public:
    int max_iter_num = 0;
    int size_num = 0;
    std::vector<cv::Mat> in_descriptors;
    cv::Mat output;
    BowDictionary();

    //~BowDictionary();

public:
    // BowDictionary();
    BowDictionary(const BowDictionary&) = delete;  // once constructor: singelaton

    static BowDictionary& GetInstance();  // destructor??


    int max_iterations();
    int size();  // number of centroids / codewords
    vector<Mat> descriptors();
    int total_features();  // number of input features

    void set_max_iterations(int max_iterations);
    void set_size(int size);
    void set_descriptors(vector<Mat> descriptors);
    void set_params(int max_iterations, int size, const vector<Mat>& descriptors);
    bool empty() const;


    // auto& GetInstance(); //??
};*/

}  // namespace ipb