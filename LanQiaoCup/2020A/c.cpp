/**
 *    author: subobo
 *    created: 04.04.2022 22:57:05
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
  int p = 1;
  for (int i = 1; i <= 40; i++) {
    for (int j = 1; j <= i; j++) {
      cout << p << " \n"[j == i];
      ++p;
    }
  }
  return 0;
}