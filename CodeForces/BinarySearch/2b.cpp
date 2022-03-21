/**
 *    author: subobo
 *    created: 20.01.2022 20:49:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& in : a) {
    cin >> in;
  }
  auto good = [&](double x) {
    int cnt = 0;
    for (auto it : a) {
      cnt += it / x;
    }
    return cnt >= k;
  };
  double l = 0, r = 1e8;
  for (int i = 0; i < 100; i++) {
    double md = (l + r) / 2;
    if (good(md)) {
      l = md;
    } else {
      r = md;
    }
  }
  cout << setprecision(20) << l << '\n';
  return 0;
}