/**
 *    author: subobo
 *    created: 09.01.2022 11:15:53
**/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pii> city(n);
  for (auto& in : city) {
    cin >> in.first >> in.second;
  }
  sort(city.begin(), city.end(), [](pii pa, pii pb) {
    return pa.second < pb.second;
  });
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (city[i].first > city[j].first) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int res = 0;
  for (auto it : dp) {
    res = max(res, it);
  }
  cout << res << '\n';
  return 0;
}
