#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"

using namespace ipb;
template <typename T>

auto accumulate(named_vector<T> vec) {
    auto v = vec.vector();
    auto accumulated = std::accumulate(v.begin(), v.end(), 0);
    return accumulated;
}

template <typename T>
auto count(named_vector<T> vec) {
    auto V = vec.vector();
    return (std::count(V.begin(), V.end(), 0));
}
template <typename T>
auto all_even(named_vector<T> vec) {
    auto V = vec.vector();
}
template <typename T>
auto clamp(named_vector<T> vec, T min, T max) {
    std::vector<T> clamped;
    for (const auto& d : vec.vector()) {
        clamped.push_back(std::clamp(d, min, max));
    }
    return vec = {vec.name(), clamped};
}
template <typename T>
auto fill(named_vector<T> vec, T number) {
    auto filled = vec.vector();
    std::fill(filled.begin(), filled.end(), number);
    return vec = {vec.name(), filled};
}
