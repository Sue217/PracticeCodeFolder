/**
 *    author: subobo
 *    created: 16.04.2022 19:07:26
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
  int t, f, s, p, c;
  cin >> t >> f >> s >> p >> c;
  cout << t * 6 + f * 3 + s * 2 + p + c * 2<< " ";
  cin >> t >> f >> s >> p >> c;
  cout << t * 6 + f * 3 + s * 2 + p + c * 2<< "\n";
  return 0;
}