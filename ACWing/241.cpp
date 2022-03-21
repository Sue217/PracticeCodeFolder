/**
 *    author: subobo
 *    created: 20.03.2022 15:22:20
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
  fenwick<long long> fenw(n + 1);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  vector<long long> V(n), A(n);
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    V[i] = fenw.get(n) - fenw.get(y[i]);
    A[i] = fenw.get(y[i] - 1);
    fenw.modify(y[i], 1);
  }
  fenw.fenw.clear();
  fenw.fenw.resize(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    ans1 += V[i] * (fenw.get(n) - fenw.get(y[i]));
    ans2 += A[i] * (fenw.get(y[i] - 1));
    fenw.modify(y[i], 1);
  }
  cout << ans1 << " " << ans2 << '\n';
  return 0;
}