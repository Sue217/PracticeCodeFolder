/**
 *    author: subobo
 *    created: 11.03.2022 11:59:09
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, L, R;
  while (cin >> n >> L >> R) {
    vector<int> s(1, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.push_back(a + s.back());
    }
    constexpr int inf = (int) 2e9;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int len = L; len <= R; len++) {
      for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        dp[l][r] = inf;
        for (int m = l; m < r; m++) {
          dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + s[r] - s[l - 1]);
        }
      }
    }
    // debug(dp[1][n]);
    cout << (dp[1][n] == inf ? 0 : dp[1][n]) << '\n';
  }
  return 0;
}