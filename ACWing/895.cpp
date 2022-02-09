/**
 *    author: subobo
 *    created: 09.02.2022 12:01:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> seq[i];
  };
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (seq[j] < seq[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}