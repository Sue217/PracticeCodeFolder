/**
 *    author: subobo
 *    created: 21.03.2022 22:42:21
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 500000;

int n, m, a[N + 1], f[4 * N + 1];
// f[]: index

inline void build(int k, int l, int r) {
  if (l == r) {
    f[k] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  // left
  build(k + k, l, mid);
  // right
  build(k + k + 1, mid + 1, r);
  f[k] = f[k + k] + f[k + k + 1];
}

inline void add(int k, int l, int r, int x, int y) {
  // index: k, [l, r]: x (+y)
  f[k] += y;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    // left child
    add(k + k, l, mid, x, y);
  } else {
    // right child
    add(k + k + 1, mid + 1, r, x, y);
  }
}

inline int calc(int k, int l, int r, int start, int finish) {
  // k: index, [l, r], calc: sum[start, finish]
  if (l == start && r == finish) {
    // coincidence
    return f[k];
  }
  int mid = (l + r) >> 1;
  if (finish <= mid) {
    // all in left
    return calc(k + k, l, mid, start, finish);
  } else {
    if (start > mid) {
      // all in right
      return calc(k + k + 1, mid + 1, r, start, finish);
    } else {
      // stretch across
      return calc(k + k, l, mid, start, mid) + calc(k + k + 1, mid + 1, r, mid + 1, finish);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      add(1, 1, n, x, y);
    }
    if (t == 2) {
      cout << calc(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}