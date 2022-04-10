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
  int tt;
  cin >> tt;
  while (tt--) {
    double h, w;
    cin >> h >> w;
    double we = (h - 100.0) * 1.8;
    double eps = 1e-9;
    double delta = abs(w - we) - we * 0.1;
    if (delta < -eps) {
      cout << "You are wan mei!" << '\n';
    } else {
      if (w - we < -eps) {
        cout << "You are tai shou le!" << '\n';
      } else {
        cout << "You are tai pang le!" << '\n';
      }
    }
  }
  return 0;
}