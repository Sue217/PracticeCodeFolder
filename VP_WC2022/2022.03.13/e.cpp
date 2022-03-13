/**
 *    author: subobo
 *    created: 13.03.2022 18:39:32
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
  double h, w;
  cin >> w >> h;
  double ans = w / (h * h);
  constexpr double eps = 1e-18;
  if (ans - 25 > eps) {
    cout << fixed << setprecision(1) << ans << '\n';
    cout << "PANG" << '\n';
  } else {
    cout << fixed << setprecision(1) << ans << '\n';
    cout << "Hai Xing" << '\n';
  }
  return 0;
}