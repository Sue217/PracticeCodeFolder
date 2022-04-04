/**
 *    author: subobo
 *    created: 04.04.2022 14:43:25
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
  int n, q;
  cin >> n >> q;
  fenwick<int> fenw(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    fenw.modify(i, +x);
  }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 0) {
      cout << fenw.get(y) - fenw.get(x - 1) << '\n';
    }
    if (op == 1) {
      fenw.modify(x, +y);
    }
  }
  return 0;
}