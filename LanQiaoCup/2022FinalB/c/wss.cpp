#include <bits/stdc++.h>
#define FastIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;

const char sp = 32, cr = 10;
const ll inf = 0x3f3f3f3f;
const ll N = 2e5 + 5, M = 2e5 + 5;

ll a[N], b[N], n, m;
bool check(ll mid, ll s) {
  for (ll i = 1; i <= n; ++i) {
    if (a[i] + b[i] < mid)
      return false;
    else {
      if (a[i] >= mid) continue;
      if (s < mid - a[i])
        return false;
      else
        s -= mid - a[i];
    }
  }
  return true;
}
int main() {
  FastIO;
  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  for (ll i = 1; i <= n; ++i) cin >> b[i];

  ll l = 0, r = 4 * n, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid, m))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r << cr;

  return 0;
}
