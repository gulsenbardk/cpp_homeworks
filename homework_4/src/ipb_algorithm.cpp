#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"

using namespace ipb;

int accumulate(named_vector<int> vector) {
    std::vector<int> v = vector.vector();
    int accumulated = std::accumulate(v.begin(), v.end(), 0);
    return accumulated;
}

int count(named_vector<int> vector, int number) {
    std::vector<int> V = vector.vector();
    int counted = std::count(V.begin(), V.end(), number);
    return (counted);
}

bool all_even(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    bool evened = std::all_of(V.cbegin(), V.cend(), [](int i) { return i % 2 == 0; });
    return (evened);
}

named_vector<int> clamp(named_vector<int> vector, int min, int max) {
    std::vector<int> clamped;
    for (const auto& d : vector.vector()) {
        clamped.push_back(std::clamp(d, min, max));
    }
    return vector = {vector.name(), clamped};
}

named_vector<int> fill(named_vector<int>& vector, int number) {
    // std::vector<int> filled = vector.vector();
    std::fill(vector.vector().begin(), vector.vector().end(), number);
    return vector;
}

bool find(named_vector<int> vector, int number) {
    std::vector<int> V = vector.vector();
    std::vector<int>::iterator it;
    it = std::find(V.begin(), V.end(), number);
    bool con = it != V.end();
    return con;
}

void print(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    std::string name = vector.name();
    std::cout << name << ", ";
    std::cout << "{ ";
    for (int i : V) {
        std::cout << i << ", ";
    }
    std::cout << " }";
}  // TODO test

named_vector<int> toupper(named_vector<int>& vector) {
    std::transform(vector.vector().begin(), vector.vector().end(), vector.vector().begin(),
                   [](char c) { return std::toupper(c); });
    return vector;
}

named_vector<int> sort(named_vector<int>& vector) {
    std::sort(vector.vector().begin(), vector.vector().end());
    return vector;
}

named_vector<int> rotate(named_vector<int>& vector, int pos) {
    std::rotate(vector.vector().begin(), vector.vector().begin() + pos, vector.vector().end());
    return vector;
}

named_vector<int> reverse(named_vector<int>& vector) {
    std::reverse(vector.vector().begin(), vector.vector().end());
    return vector;
}
