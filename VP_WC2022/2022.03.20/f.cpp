/**
 *    author: subobo
 *    created: 20.03.2022 18:11:15
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
  string s;
  cin >> s;
  string xs(s);
  reverse(xs.begin(), xs.end());
  if (xs == s) {
    cout << "yes" << '\n';
  } else {
    cout << "no" << '\n';
  }
  return 0;
}