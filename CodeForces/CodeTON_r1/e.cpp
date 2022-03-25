/**
 *    author: subobo
 *    created: 25.03.2022 22:35:21
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> que(1, 0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int v : g[que[b]]) {
        if (dist[v] == -1) {
          dist[v] = dist[que[b]] ^ 1;
          que.push_back(v);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] == 1) {
        cout << -(int) g[i].size() << " ";
      } else {
        cout << g[i].size() << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}