/**
 *    author: subobo
 *    created: 22.03.2022 22:22:22
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 100000;

int n, m, a[N + 1];
long long f[4 * N + 1], v[4 * N + 1];
// f: down, v: up

inline void build(int k, int l, int r) {
  v[k] = 0;
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

inline void insert(int k, int l, int r, int x, int y, long long z) {
  if (l == x && r == y) {
    v[k] += z;
    return;
  }
  f[k] += (y - x + 1) * z; // subtree: [x, y]
  int mid = (l + r) >> 1;
  if (y <= mid) {
    // all in left
    insert(k + k, l, mid, x, y, z);
  } else {
    if (x > mid) {
      // all in right
      insert(k + k + 1, mid + 1, r, x, y, z);
    } else {
      // stretch across
      insert(k + k, l, mid, x, mid, z);
      insert(k + k + 1, mid + 1, r, mid + 1, y, z);
    }
  }
}

inline long long calc(int k, int l, int r, int start, int finish, long long p) {
  // k: index, [l, r], calc: sum[start, finish]
  p += v[k];
  if (l == start && r == finish) {
    // coincidence
    return p * (r - l + 1) + f[k];
  }
  int mid = (l + r) >> 1;
  if (finish <= mid) {
    // all in left
    return calc(k + k, l, mid, start, finish, p);
  } else {
    if (start > mid) {
      // all in right
      return calc(k + k + 1, mid + 1, r, start, finish, p);
    } else {
      // stretch across
      return calc(k + k, l, mid, start, mid, p) + calc(k + k + 1, mid + 1, r, mid + 1, finish, p);
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
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      long long k;
      cin >> x >> y >> k;
      insert(1, 1, n, x, y, k);
    }
    if (t == 2) {
      int x, y;
      cin >> x >> y;
      cout << calc(1, 1, n, x, y, 0) << '\n';
    }
  }
  return 0;
}