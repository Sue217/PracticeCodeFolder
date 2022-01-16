/**
 *    author: subobo
 *    created: 16.01.2022 20:03:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int p = 1; p <= tt; p++) {
    cout << "Case #" << p << ": ";
    int n;
    cin >> n;
    int m = 0;
    vector<tuple<int, int, int>> stone;
    for (int i = 1; i <= n; i++) {
      int s, e, l;
      cin >> s >> e >> l;
      stone.emplace_back(s, e, l);
      m += s;
    }
    sort(stone.begin(), stone.end(), [](tuple<int, int, int> ta, tuple<int, int, int> tb) {
      return get<0>(ta) * get<2>(tb) < get<0>(tb) * get<2>(ta);
    });
    vector<int> dp(m + 1);
    for (int i = 0; i < n; i++) {
      int s = get<0>(stone[i]), e = get<1>(stone[i]), l = get<2>(stone[i]);
      for (int j = m; j >= s; j--) {
        dp[j] = max(dp[j], dp[j - s] + e - (j - s) * l);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
