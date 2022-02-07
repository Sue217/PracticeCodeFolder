/**
 *    author: subobo
 *    created: 07.02.2022 08:58:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i++) {
        cout << i << '\n';
      }
      continue;
    }
    if (n % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n * k; j += n) {
        cout << j << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}