/*
  ID: sujingb1
  TASK: frac1
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("frac1.in");
  ofstream fout ("frac1.out");
  int n;
  fin >> n;
  vector<tuple<int, int, double>> tp;
  tp.emplace_back(0, 1, 0);
  tp.emplace_back(1, 1, 1);
  for (int f = 1; f < n; f++) {
    for (int d = n; f / d < 1.0; d--) {
      int g = __gcd(f, d);
      tp.emplace_back(f / g, d / g, (double) f / d);
    }
  }
  sort(tp.begin(), tp.end(), [&](auto a, auto b) {
    if (get<0>(a) == get<0>(b)) {
      return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
  });
  tp.erase(unique(tp.begin(), tp.end(), [&](auto a, auto b) {
    return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b);
  }), tp.end());
  sort(tp.begin(), tp.end(), [&](auto a, auto b) {
    return get<2>(a) < get<2>(b);
  });
  for (auto it : tp) {
    fout << get<0>(it) << '/' << get<1>(it) << '\n';
  }
  return 0;
}