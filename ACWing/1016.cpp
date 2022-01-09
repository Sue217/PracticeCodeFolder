/**
 *    author: subobo
 *    created: 09.01.2022 11:35:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (auto& in : seq) {
    cin >> in;
  }
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = seq[i];
    for (int j = 0; j < i; j++) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[i], dp[j] + seq[i]);
      }
    }
  }
  cout << dp[max_element(dp.begin(), dp.end()) - dp.begin()] << '\n';
  return 0;
}
