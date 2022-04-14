#include <bits/stdc++.h>
#define FastIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define int ll

const int N = 1e5 + 5, M = 1e5 + 5;
const char cr = 10, sp = 32;
const int inf = 0x3f3f3f3f;

signed main() {
  FastIO;
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int sum = 0, res = 1;
    int m = 0;
    while ((1 << m) <= n)
      ++m;
    --m;
    m = min(m, k);
    int d = 1, ltd = (n + 1) / 2 * 2;
    for (int i = 0; n; n /= 2, ++i) {
      if (n % 2)
        res = (n / 2 + 1) * (n + 1) / 2;
      else
        res = n / 2 * n / 2;
      if (i >= m) {
        res *= d;
        d <<= 1;
      }
      sum += res;
    }
    cout << sum << cr;
  }
  return 0;
}
