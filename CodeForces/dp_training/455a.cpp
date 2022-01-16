/**
 *    author: subobo
 *    created: 16.01.2022 23:16:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  vector<pair<int, int>> seq;
  for (auto it : mp) {
    seq.emplace_back(it);
  }
  int m = (int) seq.size();
  vector<long long> dp(m);
  for (int i = 0; i < m; i++) {
    int index = i - 1;
    while (index >= 0 and seq[index].first + 1 == seq[i].first) {
      index--;
    }
    if (index == -1) {
      dp[i] = (long long) seq[i].first * seq[i].second;
    } else {
      dp[i] = dp[index] + (long long) seq[i].first * seq[i].second;
    }
    if (i) {
      dp[i] = max(dp[i], dp[i - 1]);
    }
  }
  cout << dp[m - 1] << '\n';
  return 0;
}