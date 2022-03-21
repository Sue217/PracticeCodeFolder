/**
 *    author: subobo
 *    created: 13.03.2022 18:42:52
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
    int x;
    cin >> x;
    int left = 0, right = 0;
    for (int i = 0; i < 3; i++) {
      right += x % 10;
      x /= 10;
    }
    for (int i = 0; i < 3; i++) {
      left += x % 10;
      x /= 10;
    }
    if (left == right) {
      cout << "You are lucky!" << '\n';
    } else {
      cout << "Wish you good luck." << '\n';
    }
  }
  return 0;
}