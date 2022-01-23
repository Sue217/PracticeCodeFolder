/**
 *    author: subobo
 *    created: 23.01.2022 21:41:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto prime = [&](int x) {
    int ans = 0;
    while (x) {
      ans += x / 5;
      x /= 5;
    }
    return ans;
  };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cout << (int) prime(x) << '\n';
  }
  return 0;
}