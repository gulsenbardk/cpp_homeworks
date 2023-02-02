#include <iostream>
#include <vector>

#include "homework_4.h"

using vector = ipb::named_vector<int>;

int main() {
    vector v2{"name", {1, 2, 3, 4}};
    vector v{"vectorname", {12, 4, 0, 1}};
    // std::cout << v.name();
    // std::cout << v.capacity();
    // std::cout << v.empty();
    ipb::clamp(v2, 2, 3);
    ipb::fill(v2, -100);
    ipb::toupper(v2);
    ipb::sort(v);
    ipb::rotate(v2, 2);
    ipb::reverse(v);
}