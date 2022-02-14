/**
 *    author: Jingbo Su
 *    created: February/14/2022 Monday
**/
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
 
int main() {
  std::vector<int> v(10, 2);

  std::cout << "The first 10 even numbers are: ";
  std::partial_sum(v.begin(), v.end(), 
                    std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  std::vector<int> t(10);
  std::partial_sum(v.begin(), v.end(), t.begin(), std::plus<int>());
  std::cout << "prefix array of v: ";
  for (auto n : t) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>()); // plus, minus, multiplies, divides
  std::cout << "The first 10 powers of 2 are: ";
  for (auto n : v) {
    std::cout << n << " ";
  }
  std::cout << '\n';
}

/*
  The first 10 even numbers are: 2 4 6 8 10 12 14 16 18 20
  prefix array of v: 2 4 6 8 10 12 14 16 18 20
  The first 10 powers of 2 are: 2 4 8 16 32 64 128 256 512 1024
*/