/**
 *    author: subobo
 *    created: 02.04.2022 13:10:59
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  function<int(int, int)> gcd = [&](int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
  };
  vector<tuple<int, int, double>> tp;
  tp.emplace_back(0, 1, 0);
  tp.emplace_back(1, 1, 1);
  for (int f = 1; f < n; f++) {
    for (int d = n; f / d < 1.0; d--) {
      int g = gcd(f, d);
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
    cout << get<0>(it) << '/' << get<1>(it) << '\n';
  }
  return 0;
}