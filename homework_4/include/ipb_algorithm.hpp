
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"

namespace ipb {
template <typename T>
auto accumulate(named_vector<T> vector);
template <typename T>
auto count(named_vector<T>& vector);
template <typename T>
auto all_even(named_vector<T> vector);
template <typename T>
auto clamp(named_vector<T> vector, T min, T max);
template <typename T>
auto fill(named_vector<T> vector, T number);

}  // namespace ipb