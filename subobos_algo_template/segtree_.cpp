#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100010;

vector<long long> tree(N * 4);
vector<long long> val(N * 4);
vector<long long> node(N);

inline void build(int x, int l, int r) {
  if (l == r) {
    tree[x] = node[l];
    return;
  }
  int m = (l + r) >> 1;
  build(x + x, l, m);
  build(x + x + 1, m + 1, r);
  tree[x] = tree[x + x] + tree[x + x + 1];
}

template <typename M>
inline void modify(int x, int l, int r, int ll, int rr, M v) {
  if (l == ll && r == rr) {
    val[x] += v;
    return;
  }
  tree[x] += v * (rr - ll + 1);
  int m = (l + r) >> 1;
  if (rr <= m) {
    modify(x + x, l, m, ll, rr, v);
  } else {
    if (ll > m) {
      modify(x + x + 1, m + 1, r, ll, rr, v);
    } else {
      modify(x + x, l, m, ll, m, v);
      modify(x + x + 1, m + 1, r, m + 1, rr, v);
    }
  }
}

template <typename M>
inline M get(int x, int l, int r, int ll, int rr, M s) {
  s += val[x];
  if (l == ll && r == rr) {
    return tree[x] + s * (rr - ll + 1);
  }
  int m = (l + r) >> 1;
  if (rr <= m) {
    return get(x + x, l, m, ll, rr, s);
  } else {
    if (ll > m) {
      return get(x + x + 1, m + 1, r, ll, rr, s);
    } else {
      return get(x + x, l, m, ll, m, s) + get(x + x + 1, m + 1, r, m + 1, rr, s);
    }
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> node[i];
  }
  build(1, 1, n);
  while (q--) {
    int op, x, y;
    long long z = 0;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> z;
      /* modify(1, 1, n, x, x, y); */
      modify(1, 1, n, x, y, z);
    }
    if (op == 2) {
      cin >> x >> y;
      /* cout << get(1, 1, n, x, y) << '\n'; */
      cout << get(1, 1, n, x, y, z) << '\n';
    }
  }
  return 0;
}