/**
 *    author: subobo
 *    created: 25.05.2022 09:19:09
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
class segtree {
 public:
  int n;
  vector<T> tree;
  vector<T> min_val;

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(n << 2);
    min_val.resize(n << 2);
  }

  template <typename M>
  inline void build(vector<M>& a, int x, int l, int r) {
    if (r == l + 1) {
      if (l < (int) a.size()) {
        tree[x] = static_cast<T> (a[l]);
        min_val[x] = static_cast<T> (a[l]);
      }
      return;
    }
    int m = (l + r) >> 1;
    build(a, x + x + 1, l, m);
    build(a, x + x + 2, m, r);
    tree[x] = tree[x + x + 1] + tree[x + x + 2];
    min_val[x] = min(min_val[x + x + 1], min_val[x + x + 2]);
  }

  template <typename M>
  inline void build(vector<M>& a) {
    build(a, 0, 0, n);
  }

  inline void modify(int x, T v, int y, int ll, int rr) {
    if (rr == ll + 1) {
      tree[y] = v;
      min_val[y] = v;
      return;
    }
    int m = (ll + rr) >> 1;
    if (x < m) {
      modify(x, v, y + y + 1, ll, m);
    } else {
      modify(x, v, y + y + 2, m, rr);
    }
    tree[y] = tree[y + y + 1] + tree[y + y + 2];
    min_val[y] = min(min_val[y + y + 1], min_val[y + y + 2]);
  }

  inline void modify(int x, T v) {
    modify(x, v, 0, 0, n);
  }

  inline T get(int x, int l, int r, int ll, int rr) {
    if (ll >= r || l >= rr) return 0;
    if (ll >= l && r >= rr) return tree[x];
    int m = (ll + rr) >> 1;
    auto left = get(x + x + 1, l, r, ll, m);
    auto right = get(x + x + 2, l, r, m, rr);
    return left + right;
  }

  inline T get(int l, int r) {
    return get(0, l, r, 0, n);
  }
  
  inline T find_min(int x, int l, int r, int ll, int rr) {
    if (ll >= r || l >= rr) return numeric_limits<T>::max();
    if (ll >= l && r >= rr) return min_val[x];
    int m = (ll + rr) >> 1;
    auto left = find_min(x + x + 1, l, r, ll, m);
    auto right = find_min(x + x + 2, l, r, m, rr);
    return min(left, right);
  }

  inline T find_min(int l, int r) {
    return find_min(0, l, r, 0, n);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  segtree<long long> st(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  st.build(a);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      long long y;
      cin >> x >> y;
      st.modify(x, y);
    }
    if (op == 2) {
      int l, r;
      cin >> l >> r;
      cout << st.get(l, r) << '\n';
      // cout << st.find_min(l, r) << '\n';
    }
  }
  return 0;
}