/**
 *    author: subobo
 *    created: 10.01.2022 13:07:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (auto &in : seq) {
    cin >> in;
  }
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (seq[i] > seq[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << dp[max_element(dp.begin(), dp.end()) - dp.begin()] << '\n';
  return 0;
}
