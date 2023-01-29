#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"

namespace ipb {
template <typename T>

auto accumulate(named_vector<T>& V) {
    auto v = V.vector();
    auto accumulated = std::accumulate(v.begin(), v.end(), 0);
    return accumulated;
}

template <typename T>
auto count(named_vector<T>& vector) {
    auto V = vector.vector();
    return (std::count(V.begin(), V.end(), 0));
}
template <typename T>
auto all_even(named_vector<T>& vector) {
    auto V = vector.vector();
}
template <typename T>
auto clamp(named_vector<T>& vector, T min, T max) {
    std::vector<T> clamped;
    for (const auto& d : vector.vector()) {
        clamped.push_back(std::clamp(d, min, max));
    }
    return vector = {vector.name(), clamped};
}
template <typename T>
auto fill(named_vector<T>& vector, T number) {
    auto filled = vector.vector();
    std::fill(filled.begin(), filled.end(), number);
    return vector = {vector.name(), filled};
}

}  // namespace ipb