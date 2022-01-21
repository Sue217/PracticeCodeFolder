/**
 *    author: subobo
 *    created: 21.01.2022 15:46:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int T = 1 << n;
  unordered_map<int, int> cnt;
  vector<int> state;
  vector<vector<int>> transition(T);
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(T)));
  auto check = [&](int st) {
    return !(st & st >> 1);
  };
  auto count = [&](int st) {
    int v = 0;
    for (int i = 0; i < n; i++) {
      v += st >> i & 1;
    }
    return v;
  };
  for (int st = 0; st < T; st++) {
    if (check(st)) {
      state.emplace_back(st);
      cnt[st] = count(st);
    }
  }
  for (auto i : state) {
    for (auto j : state) {
      if ((i & j) == 0 && check(i | j)) {
        transition[i].emplace_back(j);
      }
    }
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (auto st : state) {
        for (auto tr : transition[st]) {
          if (j >= cnt[st]) {
            dp[i][j][st] += dp[i - 1][j - cnt[st]][tr];
          }
        }
      }
    }
  }
  long long ans = 0;
  for (auto st : state) {
    ans += dp[n][m][st];
  }
  cout << ans << '\n';
  return 0;
}
