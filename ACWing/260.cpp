/**
 *    author: subobo
 *    created: 20.03.2022 23:27:24
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
    fenwick<long long> fenw(n + 1);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      int p, v;
      cin >> p >> v;
      ++p;
      a.emplace_back(p, v);
      fenw.modify(i + 1, 1);
    }
    vector<int> ans(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      int low = 1, high = n;
      while (low < high) {
        int mid = (low + high) / 2;
        if (fenw.get(mid) >= a[i].first) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      // debug(low, high);
      ans[high] = a[i].second;
      fenw.modify(high, -1);
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
  return 0;
}