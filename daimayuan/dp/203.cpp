/**
 *    author: subobo
 *    created: 10.03.2022 20:44:40
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
  int n, W;
  const int N = 30;
  while (cin >> n >> W, n != -1 && W != -1) {
    vector<vector<pair<int, int>>> all(N + 1);
    int volume = 0;
    for (int i = 0; i < n; i++) {
      int w, v;
      cin >> w >> v;
      int at = __builtin_ctz(w);
      w >>= at;
      all[at].emplace_back(w, v);
      volume += w;
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = W; j >= w[i]; j--) {
    //     dp[j] = max(dp[j], dp[j - w] + v);
    //   }
    // }
    const long long inf = (long long) 2e18;
    vector<long long> dp(volume + 1, -inf), roll(volume + 1, -inf);
    dp[0] = 0;
    for (int i = N; i >= 0; i--) {
      //! roll = std::move(dp);
      roll = dp;
      fill(dp.begin(), dp.end(), -inf);
      for (int j = 0; j <= volume; j++) {
        int has = min(volume, (j << 1) + ((W >> i) & 1));
        dp[has] = max(dp[has], roll[j]);
      }
      // i + 1 -> i
      for (int j = volume - 1; j >= 0; j--) {
        dp[j] = max(dp[j], dp[j + 1]);
      }
      for (auto p : all[i]) {
        for (int w = p.first; w <= volume; w++) {
          dp[w - p.first] = max(dp[w - p.first], dp[w] + p.second);
        }
      }
    }
    cout << dp[0] << '\n';
  }
  return 0;
}