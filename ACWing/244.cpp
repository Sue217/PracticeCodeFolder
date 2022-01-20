/**
 *    author: subobo
 *    created: 20.01.2022 11:46:15
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class fenwick{
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  inline void modify(int x, T v) {
    for (int i = x; i <= n; i += (i & -i)) {
      fenw[i] += v;
    }
  }

  inline T get(int x) {
    T v{};
    for (int i = x; i >= 1; i -= (i & -i)) {
      v += fenw[i];
    }
    return v;
  }

  inline void init(int n) {
    for (int i = 1; i <= n; i++) {
      fenw[i] = (i & -i);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> h[i];
  }
  fenwick<int> fenw(n + 3);
  fenw.init(n + 1);
  vector<int> ans(n + 1);
  for (int i = n; i >= 1; i--) {
    int l = 1, r = n;
    while (l < r) {
      int md = (l + r) >> 1;
      if (fenw.get(md) >= h[i] + 1) {
        r = md;
      } else {
        l = md + 1;
      }
    }
    ans[i] = r;
    fenw.modify(r, -1);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
