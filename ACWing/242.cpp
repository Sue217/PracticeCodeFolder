/**
 *    author: subobo
 *    created: 19.01.2022 22:53:28
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

   inline void modify(int x, T v) {
     while (x <= n) {
       fenw[x] += v;
       x += (x & -x);
     }
   }

   inline T get(int x) {
     T v{};
     while (x > 0) {
       v += fenw[x];
       x -= (x & -x);
     }
     return v;
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
    if (op == 'Q') {
      int x;
      cin >> x;
      cout << fenw.get(x) << '\n';
    } else
    if (op == 'C') {
      int l, r, d;
      cin >> l >> r >> d;
      fenw.modify(l, d);
      fenw.modify(r + 1, -d);
    }
  }
  return 0;
}
