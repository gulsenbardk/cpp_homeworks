#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace ipb {
template <typename T>
struct named_vector {
    std::string nameV;
    std::vector<T> Vector;

    auto name() { return nameV; }
    auto vector() { Vector; }
    auto size() { return nameV.size() + Vector.size(); }
    auto capacity() { return Vector.capacity(); }
    auto resize(int len) { return Vector.resize(len); }
    auto reserve(int n) { return Vector.reserve(n); }
    auto empty() { return (nameV.empty() || Vector.empty()) ? 1 : 0; }
};

}  // namespace ipb