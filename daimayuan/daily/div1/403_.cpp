/**
 *    author: subobo
 *    created: 21.03.2022 21:02:06
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int N = (int) 1e6;
  vector<int> cnt(N + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  int ans = 0;
  for (int x = 1; x <= N; x++) {
    for (int y = x + 1; y <= N; y++) {
      int ai = x, aj = y * y - x * x;
      if (aj > N) {
        break;
      }
      ans += cnt[ai] * cnt[aj];
    }
  }
  cout << ans << '\n';
  return 0;
}