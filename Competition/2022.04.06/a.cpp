/**
 *    author: subobo
 *    created: 06.04.2022 11:19:01
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), 0ll);
    int day = 0;
    long long remain = 0;
    while (m--) {
      int d, b;
      cin >> d >> b;
      int delta = d - day;
      long long growth = (long long) delta * sum + remain;
      long long ans = max(0ll, growth - 1ll * n * b);
      remain = 1ll * n * b;
      day = d;
      cout << ans << '\n';
    }
  }
  return 0;
}