/**
 *    author: subobo
 *    created: 20.03.2022 17:37:01
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
  while (cin >> n, n != 0) {
    map<long long, int> m;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      m[x] = i;
    }
    vector<int> a(n);
    int val = 1;
    for (auto [v, p] : m) {
      a[p] = val++;
    }
    fenwick<long long> fenw(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += fenw.get(n) - fenw.get(a[i]);
      fenw.modify(a[i], 1);
    }
    cout << ans << '\n';
  }
  return 0;
}