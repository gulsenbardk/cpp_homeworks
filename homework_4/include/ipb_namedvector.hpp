#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "homework_4.h"
#ifndef IPB_NAMEDVECTOR_HPP
#define IPB_NAMEDVECTOR_HPP
namespace ipb {

template <typename T>

struct named_vector {
    std::string nameVector;
    std::vector<T> vector1;
    // named_vector<T>(std::string name, std::vector<T> vector2)
    //     : nameVector(std::move(name)), vector1(vector2) {}
    //
    std::string name() { return nameVector; }
    std::vector<T> vector() { return vector1; }
    auto size() { return nameVector.size() + vector1.size(); }  // ?
    auto capacity() { return vector1.capacity(); }              // ?
    void resize(int len) { return vector1.resize(len); }
    void reserve(int n) { return vector1.reserve(n); }
    bool empty() { return (nameVector.empty() || vector1.empty()); }
};

}  // namespace ipb

#endif