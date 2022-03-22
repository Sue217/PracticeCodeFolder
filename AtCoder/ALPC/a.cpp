/**
 *    author: subobo
 *    created: 22.03.2022 18:19:12
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
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    int yy;
    cin >> x[i] >> yy;
    --x[i]; --yy;
    y[x[i]] = yy;
  }
  vector<int> order(n);
  for (int xx = 0; xx < n; ) {
    int yy = y[xx];
    int xa = xx + 1;
    while (xa < n - yy) {
      yy = min(yy, y[xa]);
      xa += 1;
    }
    for (int i = xx; i < xa; i++) {
      order[i] = xa - xx;
    }
    xx = xa;
  }
  for (int i = 0; i < n; i++) {
    cout << order[x[i]] << '\n';
  }
  return 0;
}