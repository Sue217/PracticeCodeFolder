/**
 *    author: subobo
 *    created: 23.03.2022 11:51:35
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
  a.push_back(m);
  int r = m / (n + 1);
  int gx = 0;
  int last = r;
  long long ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    int L = a[i - 1];
    for (; ;) {
      if (a[i] < last) {
        ans += (long long) abs(i - 1 - gx) * (a[i] - L) * 1ll;
        break;
      } else {
        ans += (long long) abs(i - 1 - gx) * (last - L) * 1ll;
        L = last;
        last += r;
        ++gx;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}