/**
 *    author: subobo
 *    created: 21.03.2022 10:57:09
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  fenwick<int> fenw(n + 4);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fenw.modify(i, a[i] - a[i - 1]);
  }
  while (m--) {
    char op;
    cin >> op;
    if (op == 'Q') {
      int x;
      cin >> x;
      cout << fenw.get(x) << '\n';
    }
    if (op == 'C') {
      int l, r, d;
      cin >> l >> r >> d;
      fenw.modify(l, +d);
      fenw.modify(r + 1, -d);
    }
  }
  return 0;
}