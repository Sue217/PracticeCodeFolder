/**
 *    author: subobo
 *    created: 21.03.2022 12:05:57
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
  vector<T> fenw, p;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
    p.resize(n);
  }

  void modify(int x, T v) {
    T u = (T) x * v;
    while (x < n) {
      fenw[x] += v;
      p[x] += u;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{}, u{};
    int y = x;
    while (y >= 0) {
      v += fenw[y];
      u += p[y];
      y = (y & (y + 1)) - 1;
    }
    return v * (x + 1) - u;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick<long long> fenw(n + 4);
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fenw.modify(i, a[i] - a[i - 1]);
  }
  while (q--) {
    char op;
    cin >> op;
    if (op == 'C') {
      int l, r, d;
      cin >> l >> r >> d;
      fenw.modify(l, +d);
      fenw.modify(r + 1, -d);
    }
    if (op == 'Q') {
      int l, r;
      cin >> l >> r;
      cout << fenw.get(r) - fenw.get(l - 1) << '\n';
    }
  }
  return 0;
}