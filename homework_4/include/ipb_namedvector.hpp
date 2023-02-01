#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "homework_4.h"

namespace ipb {

template <typename T>

struct named_vector {
public:
    std::string nameV;
    std::vector<T> vec;
    named_vector<T>(std::string name, std::vector<T> vec2) : nameV(std::move(name)), vec(vec2) {}
    auto name() { return nameV; }
    auto vector() { return vec; }
    auto size() { return nameV.size() + vec.size(); }
    auto capacity() { return vec.capacity(); }
    auto resize(int len) { return vec.resize(len); }
    auto reserve(int n) { return vec.reserve(n); }
    auto empty() { return (nameV.empty() || vec.empty()) ? 1 : 0; }
};

}  // namespace ipb