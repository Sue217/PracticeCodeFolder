/**
 *    author: subobo
 *    created: 10.04.2022 15:12:55
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
  double h;
  cin >> h;
  double w = (h - 100.0) * 1.8;
  cout << fixed << setprecision(1) << w << '\n';
  return 0;
}