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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x] += 1;
  }
  const int N = (int) 1e6;
  int ans = 0;
  for (int x = 1; x <= N; x++) {
    for (int y = x + 1; y <= N; y += x) {
      int ai = x, aj = y * y - x * x;
      if (aj > N) {
        break;
      }
      ans += m[ai] * m[aj];
    }
  }
  cout << ans << '\n';
  return 0;
}