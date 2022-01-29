/**
 *    author: subobo
 *    created: 29.01.2022 09:30:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m, n != 0 && m != 0) {
    const int T = 1 << n;
    vector<bool> state(T + 1);
    for (int st = 0; st < T; st++) {
      int cnt = 0;
      bool ok = true;
      for (int bit = 0; bit < n; bit++) {
        if (st >> bit & 1) {
          if (cnt % 2) {
            ok = false;
            break;
          }
          cnt = 0;
        } else {
          cnt += 1;
        }
      }
      if (cnt % 2) {
        ok = false;
      }
      state[st] = ok;
    }
    vector<vector<int>> transition(T + 1);
    for (int i = 0; i < T; i++) {
      for (int j = 0; j < T; j++) {
        if ((i & j) == 0 && state[i | j]) {
          transition[i].emplace_back(j);
        }
      }
    }
    vector<vector<long long>> dp(m + 1, vector<long long>(T + 1));
    dp[0][0] = 1;
    for (int id = 1; id <= m; id++) {
      for (int st = 0; st < T; st++) {
        for (int tr : transition[st]) {
          dp[id][st] += dp[id - 1][tr];
        }
      }
    }
    cout << dp[m][0] << '\n';
  }
  return 0;
}