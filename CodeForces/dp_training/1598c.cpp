/**
 *    author: subobo
 *    created: 04.02.2022 23:02:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& in : a) {
      cin >> in;
      cnt[in] += 1;
      sum += in;
    }
    if ((2 * sum) % n != 0) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = 0, need = 2 * sum / n;
    for (int it : a) {
      if (cnt.count(need - it) != 0) {
        ans += cnt[need - it];
      }
      if (it == need - it) {
        ans -= 1;
      }
    }
    cout << ans / 2 << '\n';
  }
  return 0;
}