/**
 *    author: subobo
 *    created: 20.01.2022 10:30:38
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw, psum;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
    psum.resize(n);
  }

  inline void modify(int x, T v) {
    for (int i = x; i <= n; i += (i & -i)) {
      fenw[i] += v;
      psum[i] += 1ll * x * v;
    }
  }

  inline T get(int x) {
    T v{}, u{};
    for (int i = x; i >= 1; i -= (i & -i)) {
      v += fenw[i];
      u += psum[i];
    }
    return v * (x + 1) - u;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> seq(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> seq[i];
  }
  fenwick<long long> fenw(n + 3);
  for (int i = 1; i <= n; i++) {
    fenw.modify(i, seq[i] - seq[i - 1]);
  }
  for (int i = 0; i < m; i++) {
    char op;
    cin >> op;
    if (op == 'C') {
      int l, r;
      long long d;
      cin >> l >> r >> d;
      fenw.modify(l, d);
      fenw.modify(r + 1, -d);
    } else
    if (op == 'Q') {
      int l, r;
      cin >> l >> r;
      cout << fenw.get(r) - fenw.get(l - 1) << '\n';
    }
  }
  return 0;
}
