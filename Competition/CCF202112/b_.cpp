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
  // calc sum of gx
  auto gx = [&](int x, int y)->long long {
    if (x / r == y / r) {
      return 1ll * (y - x + 1) * (x / r);
    }
    long long a = x / r + 1, b = y / r - 1;
    // mid
    long long ans = 1ll * r * (a + b) * (b - a + 1) / 2;
    // left
    ans += (a - 1) * (1ll * a * r - x);
    // right
    ans += (b + 1) * 1ll * (y - (b * r + r) + 1);
    return ans;
  };
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    int x = a[i], y = a[i + 1] - 1;
    int a = x / r, b = y / r;
    if (b <= i || i <= a) {
      ans += (long long) abs(1ll * i * (y - x + 1) - gx(x, y));
    } else {
      long long mid = 1ll * i * r;
      ans += (long long) abs(1ll * i * (mid - x + 1) - gx(x, mid));
      ans += (long long) abs(1ll * i * (y - mid) - gx(mid + 1, y));
    }
  }
  cout << ans << '\n';
  return 0;
}