/**
 *    author: subobo
 *    created: 20.03.2022 19:14:43
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
  string brac;
  while (cin >> brac) {
    int n = (int) brac.size();
    int lb = 0, rb = 0;
    for (int i = 0; i < n; i++) {
      if (brac[i] == '(') {
        rb += 1;
      } else {
        if (rb != 0) {
          rb -= 1;
        } else {
          lb += 1;
        }
      }
    }
    if (rb == 0 && lb == 0) {
      cout << "Match" << '\n';
    } else {
      cout << rb + lb << '\n';
      cout << string(lb, '(') + brac + string(rb, ')') << '\n';
    }
  }
  return 0;
}