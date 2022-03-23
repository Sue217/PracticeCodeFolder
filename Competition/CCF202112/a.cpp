/**
 *    author: subobo
 *    created: 23.03.2022 11:24:34
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  int mx = *max_element(a.begin(), a.end());
  int start = a[1], last = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i] - start) * last;
    start = a[i];
    ++last;
  }
  ans += (m - mx) * n;
  cout << ans << '\n';
  return 0;
}