#include <iostream>
#include <vector>

#include "homework_4.h"

using vector = ipb::named_vector<int>;

int main() {
    vector v{"vectorname", {1, 2, 3, 4, 5}};
    std::cout << v.name();
    std::cout << v.capacity();
    std::cout << v.empty();

    // std::cout << ipb::accumulate(v);
}