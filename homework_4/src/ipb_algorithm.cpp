#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"

using namespace ipb;

int ipb::accumulate(named_vector<int> vector) {
    std::vector<int> v = vector.vector();
    int accumulated = std::accumulate(v.begin(), v.end(), 0);
    return accumulated;
}

int ipb::count(named_vector<int> vector, int number) {
    std::vector<int> V = vector.vector();
    int counted = std::count(V.begin(), V.end(), number);
    return (counted);
}

bool ipb::all_even(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    bool evened = std::all_of(V.cbegin(), V.cend(), [](int i) { return i % 2 == 0; });
    return (evened);
}

named_vector<int> ipb::clamp(named_vector<int> vector, int min, int max) {
    std::vector<int> V;
    for (const auto& ref : vector.vector()) {
        V.push_back(std::clamp(ref, min, max));
    }
    named_vector<int> clamped = {vector.name(), V};
    return clamped;
}

named_vector<int> ipb::fill(named_vector<int> vector, int number) {
    std::vector<int> V = vector.vector();
    std::fill(V.begin(), V.end(), number);
    named_vector<int> filled = {vector.name(), V};
    return filled;
}

bool ipb::find(named_vector<int> vector, int number) {
    std::vector<int> V = vector.vector();
    std::vector<int>::iterator it;
    it = std::find(V.begin(), V.end(), number);
    bool con = it != V.end();
    return con;
}

void ipb::print(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    std::string name = vector.name();
    std::cout << name << ", ";
    std::cout << "{ ";
    for (int i : V) {
        std::cout << i << ", ";
    }
    std::cout << " }";
}  // TODO test

named_vector<int> ipb::toupper(named_vector<int> vector) {
    std::string name = vector.name();
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    named_vector<int> uppered = {name, vector.vector()};
    // std::string test_name = uppered.name();
    // for (int i : test_name) {
    //     std::cout << i << std::endl;
    // }
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    return uppered;
    // return vector;
}

named_vector<int> ipb::sort(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    std::sort(V.begin(), V.end());
    named_vector<int> sorted = {vector.name(), V};
    // std::vector<int> test_vector = sorted.vector();
    // for (int i : test_vector) {
    //     std::cout << i << std::endl;
    // }
    // std::sort(vector.vector().begin(), vector.vector().end());
    // return vector;
    return sorted;
}

named_vector<int> ipb::rotate(named_vector<int> vector, int pos) {
    std::vector<int> V = vector.vector();
    std::rotate(V.begin(), V.begin() + pos, V.end());
    named_vector<int> rotated = {vector.name(), V};
    // std::vector<int> test_vector = rotated.vector();
    // for (int i : test_vector) {
    //     std::cout << i << std::endl;
    // }
    // std::rotate(vector.vector().begin(), vector.vector().begin() + pos, vector.vector().end());

    return rotated;
}

named_vector<int> ipb::reverse(named_vector<int> vector) {
    std::vector<int> V = vector.vector();
    std::reverse(V.begin(), V.end());
    named_vector<int> reversed = {vector.name(), V};
    // std::vector<int> test_vector = reversed.vector();
    // for (int i : test_vector) {
    //     std::cout << i << std::endl;
    // }
    // std::reverse(vector.vector().end(), vector.vector().begin());

    return reversed;
}
