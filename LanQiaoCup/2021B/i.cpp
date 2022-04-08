/**
 *    author: subobo
 *    created: 08.04.2022 15:45:48
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
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  while (m--) {
    int p, q;
    cin >> p >> q;
    --q;
    if (p == 0) {
      sort(a.begin(), a.begin() + q + 1, [&](int x, int y) {return x > y;});
    }
    if (p == 1) {
      sort(a.begin() + q, a.end());
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n];
  }
  // cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}