/**
 *    author: subobo
 *    created: 12.01.2022 23:02:00
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
    vector<int> seq(n);
    for (auto& in : seq) {
      cin >> in;
    }
    map<int, int> mp;
    int res = -1;
    for (int i = 0; i < n; i++) {
      auto it = mp.find(seq[i]);
      if (it != mp.end()) {
        res = max(res, n - (i - it->second));
      }
      mp[seq[i]] = i;
    }
    cout << res << '\n';
  }
  return 0;
}
