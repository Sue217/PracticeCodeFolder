/**
 *    author: subobo
 *    created: 04.04.2022 15:30:17
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
  int n;
  cin >> n;
  const int N = 32000;
  fenwick<int> fenw(N + 1);
  vector<int> layer(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    layer[fenw.get(x)] += 1;
    fenw.modify(x, +1);
  }
  for (int i = 0; i < n; i++) {
    cout << layer[i] << '\n';
  }
  return 0;
}