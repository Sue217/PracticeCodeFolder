/**
 *    author: Jingbo Su
 *    created: 25.05.2022
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
  vector<pair<T, int>> node;

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(n << 2);
    node.resize(n << 2);
  }

  T pull(const T& a, const T& b) const {
    return a + b;
  }

  pair<T, int> unite(const pair<T, int>& a, const pair<T, int>& b) const {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    return make_pair(a.first, a.second + b.second);
  }

  template <typename M>
  inline void build(vector<M>& a, int x, int l, int r) {
    if (r == l + 1) {
      if (l < (int) a.size()) {
        tree[x] = static_cast<T> (a[l]);
        node[x] = make_pair(static_cast<T> (a[l]), 1);
      }
      return;
    }
    int m = (l + r) >> 1;
    build(a, x + x + 1, l, m);
    build(a, x + x + 2, m, r);
    tree[x] = pull(tree[x + x + 1], tree[x + x + 2]);
    node[x] = unite(node[x + x + 1], node[x + x + 2]);
  }

  template <typename M>
  inline void build(vector<M>& a) {
    build(a, 0, 0, n);
  }

  inline void modify(int x, T v, int y, int l, int r) {
    if (r == l + 1) {
      tree[y] = v;
      node[y].first = v;
      return;
    }
    int m = (l + r) >> 1;
    if (x < m) {
      modify(x, v, y + y + 1, l, m);
    } else {
      modify(x, v, y + y + 2, m, r);
    }
    tree[y] = pull(tree[y + y + 1], tree[y + y + 2]);
    node[y] = unite(node[y + y + 1], node[y + y + 2]);
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
    return pull(left, right);
  }

  inline T get(int l, int r) {
    return get(0, l, r, 0, n);
  }
  
  inline pair<T, int> find(int x, int l, int r, int ll, int rr) {
    if (ll >= r || l >= rr) return make_pair(numeric_limits<T>::max(), 0);
    if (ll >= l && r >= rr) return node[x];
    int m = (ll + rr) >> 1;
    auto left = find(x + x + 1, l, r, ll, m);
    auto right = find(x + x + 2, l, r, m, rr);
    return unite(left, right);
  }

  inline pair<T, int> find(int l, int r) {
    return find(0, l, r, 0, n);
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
      cout << st.find(l, r).first << " " << st.find(l, r).second << '\n';
    }
  }
  return 0;
}