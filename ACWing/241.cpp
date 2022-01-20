/**
 *    author: subobo
 *    created: 19.01.2022 20:58:32
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
    while (x >= 1) {
      v += fenw[x];
      x -= (x & -x);
    }
    return v;
  }

  void remake(int _n, T v) {
    fenw.assign(_n, v);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> y(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> y[i];
  }
  fenwick<long long> fenw(n + 1);
  vector<long long> V(n + 1), A(n + 1);
  for (int i = 1; i <= n; i++) {
    V[i] = fenw.get(n) - fenw.get(y[i]);
    A[i] = fenw.get(y[i] - 1);
    fenw.modify(y[i], 1);
  }
  fenw.remake(n + 1, 0);
  long long ans1 = 0, ans2 = 0;
  for (int i = n; i >= 1; i--) {
    ans1 += V[i] * (long long) (fenw.get(n) - fenw.get(y[i]));
    ans2 += A[i] * (long long) fenw.get(y[i] - 1);
    fenw.modify(y[i], 1);
  }
  cout << ans1 << " " << ans2 << '\n';
  return 0;
}
