/**
 *    author: subobo
 *    created: 27.03.2022 21:17:51
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  vector<pair<int, int>> e;
  for (int i = 0; i < n; i++) {
    e.emplace_back(a[i], ~i);
  }
  for (int i = 0; i < m; i++) {
    e.emplace_back(c[i], i);
  }
  sort(e.rbegin(), e.rend());
  multiset<int> s;
  for (auto p : e) {
    int id = p.second;
    if (id >= 0) {
      s.insert(d[id]);
    } else {
      id = ~id;
      auto it = s.lower_bound(b[id]);
      if (it != s.end()) {
        s.erase(it);
      } else {
        cout << "No" << '\n';
        return 0;
      }
    }
  }
  cout << "Yes" << '\n';
  return 0;
}