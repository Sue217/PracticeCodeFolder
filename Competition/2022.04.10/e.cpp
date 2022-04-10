/**
 *    author: subobo
 *    created: 10.04.2022 15:11:47
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
  string s = "I Love GPLT";
  for (char c : s) {
    cout << c << '\n';
  }
  return 0;
}