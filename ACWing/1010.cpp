/**
 *    author: subobo
 *    created: 09.01.2022 14:32:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int height;
  vector<int> seq;
  while (cin >> height) {
    seq.emplace_back(height);
  }
  int n = (int)seq.size();
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (seq[j] >= seq[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << dp[max_element(dp.begin(), dp.end()) - dp.begin()] << '\n';
  int res = 0;
  vector<int> systems;
  for (int i = 0; i < n; i++) {
    if (!res || systems[max_element(systems.begin(), systems.end()) - systems.begin()] < seq[i]) {
      systems.emplace_back(seq[i]);
      res++;
    } else {
      int pos = lower_bound(systems.begin(), systems.end(), seq[i]) - systems.begin();
      systems[pos] = seq[i];
    }
  }
  cout << res << '\n';
  return 0;
}
