#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

vector<int> seg(N * 4 + 1);

// build(1, n, n);
inline void build(int x, int l, int r) {
  if (l == r) {
    seg[x] = l;
    return;
  }
  int m = (l + r) >> 1;
  build(x + x, l, m);
  build(x + x + 1, m + 1, r);
  seg[x] = seg[x + x] + seg[x + x + 1];
}

// modify(1, 1, n, x, y)
inline void modify(int x, int l, int r, int y, int z) {
  seg[x] += y;
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m) {
    modify(x + x, l, m, y, z);
  } else {
    modify(x + x + 1, m + 1, r, y, z);
  }
}

// get(1, 1, n, l, r)
inline int get(int x, int l, int r, int ll, int rr) {
  if (l == ll && r == rr) {
    return seg[x];
  }
  int m = (l + r) >> 1;
  if (rr <= m) {
    return get(x + x, l, m, ll, rr);
  } else {
    if (ll > m) {
      return get(x + x + 1, m + 1, r, ll, rr);
    } else {
      return get(x + x, l, m, ll, m) + get(x + x + 1, m + 1, r, m + 1, rr);
    }
  }
}

int main() {
  return 0;
}