/**
 *    author: subobo
 *    created: 23.02.2022 18:57:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    map<long long, long long> dir;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      dir[x] += 1;
    }
    for (auto [v, num] : dir) {
      if (dir.count(v * x) != 0) {
        while (dir[v] > 0 && dir[v * x] > 0) {
          dir[v] -= 1;
          dir[v * x] -= 1;
        }
      }
    }
    long long ans = 0;
    for (auto it : dir) {
      ans += (long long) it.second;
    }
    cout << ans << '\n';
  }
  return 0;
}