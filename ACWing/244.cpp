/**
 *    author: subobo
 *    created: 21.03.2022 14:30:36
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
  fenwick<long long> fenw(n + 4);
  for (int i = 1; i <= n; i++) {
    fenw.modify(i, +1);
  }
  vector<int> a(n + 1);
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    a[i] += 1;
  }
  vector<int> order;
  for (int i = n; i >= 1; i--) {
    int low = 0, high = n;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (fenw.get(mid) >= a[i]) {
        high = mid;
      } else {
        low = mid;
      }
    }
    order.push_back(high);
    fenw.modify(high, -1);
  }
  reverse(order.begin(), order.end());
  for (int i = 0; i < n; i++) {
    cout << order[i] << '\n';
  }
  return 0;
}