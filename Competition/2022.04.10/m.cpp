/**
 *    author: subobo
 *    created: 10.04.2022 14:05:57
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : get(p[x]));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[y] = x;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  constexpr int N = 1000;
  dsu d(N);
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    cin.get();
    int x;
    cin >> x;
    --x;
    f[i] = x;
    for (int j = 0; j < m - 1; j++) {
      int y;
      cin >> y;
      --y;
      d.unite(x, y);
    }
  }
  map<int, int> s;
  for (int i = 0; i < n; i++) {
    s[d.get(f[i])] += 1;
  }
  int has = (int) s.size();
  cout << has << '\n';
  if (has == 0) return 0;
  vector<int> ans;
  for (auto it : s) {
    ans.push_back(it.second);
  }
  sort(ans.rbegin(), ans.rend());
  for (int i = 0; i < has; i++) {
    cout << ans[i] << " \n"[i == has - 1];
  }
  return 0;
}