/**
 *    author: subobo
 *    created: 25.02.2022 19:21:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] += 1;
  }
  sort(a.begin(), a.end());
  int ma = *max_element(a.begin(), a.end());
  int ans = 0;
  for (int it : a) {
    if (mp.count(it) == 0) {
      continue;
    }
    int cnt = 0;
    for (int k = it; k <= ma; k *= it) {
      cnt += 1;
      mp[k] = 0;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}