#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, T;
  cin >> N >> M >> T;
  vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
  for (int i = 1; i <= N; i++) {
    int m, t;
    cin >> m >> t;
    for (int j = M; j - m >= 0; j--) {
      for (int k = T; k - t >= 0; k--) {
        dp[j][k] = max(dp[j][k], dp[j - m][k - t] + 1);
      }
    }
  }
  cout << dp[M][T] << '\n';
  return 0;
}