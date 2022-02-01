/**
 *    author: subobo
 *    created: 01.02.2022 21:43:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  set<int> dir;
  map<int, int> cnt;
  dir.insert(k);
  cnt[k] += 1;
  for (int i = 1; i < n; i++) {
    int r, d, e;
    cin >> r >> d >> e;
    dir.insert(r);
    dir.insert(e);
    cnt[r] += 1;
    cnt[e] += 1;
  }
  int ans = 0;
  for (auto it : dir) {
    if (cnt[it] == 1) {
      ans += it;
    }
  }
  cout << ans << '\n';
  return 0;
}