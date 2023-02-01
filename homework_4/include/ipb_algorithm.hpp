
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "homework_4.h"
#include "ipb_namedvector.hpp"
#ifndef IPB_ALGORITHM_HPP
#define IPB_ALGORITHM_HPP
namespace ipb {

int accumulate(named_vector<int>);

int count(named_vector<int>, int number);

bool all_even(named_vector<int>);

named_vector<int> clamp(named_vector<int>& vector, int min, int max);  // vector

named_vector<int> fill(named_vector<int>& vector, int number);  // vector

bool find(named_vector<int> vector, int number);  // bool

void print(named_vector<int>);  // vector

named_vector<int> toupper(named_vector<int>&);  // vector

named_vector<int> sort(named_vector<int>&);  // vector

named_vector<int> rotate(named_vector<int>&, int pos);  // vector

named_vector<int> reverse(named_vector<int>&);  // vector

}  // namespace ipb
#endif