/**
 *    author: subobo
 *    created: 27.03.2022 13:13:30
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (make_pair(a, b) <= make_pair(c, d) ? "Takahashi" : "Aoki") << '\n';
  return 0;
}