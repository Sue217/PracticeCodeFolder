/**
 *    author: Jingbo Su
 *    created: February/14/2022 Monday
**/
#include <vector>
#include <iostream>
#include <algorithm>
 
auto print = [](auto const& remark, auto const& v) {
  std::cout << remark;
  for (int n: v)
    std::cout << n << ' ';
  std::cout << '\n';
};
 
int main() {
  std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};

  print("before sort:\t\t", v);

  // insertion sort
  for (auto i = v.begin(); i != v.end(); ++i) {
    std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
  }

  print("after sort:\t\t", v);

  // simple rotation to the left
  std::rotate(v.begin(), v.begin() + 1, v.end());

  print("simple rotate left:\t", v);

  // simple rotation to the right
  std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

  print("simple rotate right:\t", v);
}

/*
  before sort:		2 4 2 0 5 10 7 3 7 1
  after sort:		0 1 2 2 3 4 5 7 7 10
  simple rotate left:	1 2 2 3 4 5 7 7 10 0
  simple rotate right:	0 1 2 2 3 4 5 7 7 10
*/