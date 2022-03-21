/**
 *    author: subobo
 *    created: 21.03.2022 15:09:05
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
  while (cin >> n) {
    fenwick<int> fenw(n + 1);
    vector<pair<int, int>> a(1);
    for (int i = 1; i <= n; i++) {
      int p, x;
      cin >> p >> x;
      ++p;
      a.emplace_back(p, x);
      fenw.modify(i, +1);
    }
    a[1].first = 1;
    vector<int> order(n);
    for (int i = n; i >= 1; i--) {
      int low = 0, high = n;
      while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (fenw.get(mid) >= a[i].first) {
          high = mid;
        } else {
          low = mid;
        }
      }
      order[high - 1] = a[i].second;
      fenw.modify(high, -1);
    }
    for (int i = 0; i < n; i++) {
      cout << order[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}