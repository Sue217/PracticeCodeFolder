/**
 *    author: subobo
 *    created: 30.01.2022 21:17:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> H(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> H[i];
  }
  vector<int> h(m + 1, -1), e(m + 1), ne(m + 1), w(m + 1);
  int idx = 0;
  auto Add = [&](int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int w = 0;
    if (H[u] > H[v]) {
      w = H[u] - H[v];
    } else
    if (H[u] < H[v]) {
      w = 2 * (H[u] - H[v]);
    }
    Add(u, v, w);
  }
  vector<int> happy(n + 1, -(int) 2e9);
  happy[1] = 0;
  auto spfa = [&]() {
    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1);
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      vis[t] = false;
      for (int i = h[t]; ~i; i = ne[i]) {
        int j = e[i];
        if (happy[j] < happy[t] + w[i]) {
          happy[j] = happy[t] + w[i];
          if (!vis[j]) {
            vis[j] = true;
            q.push(j);
          }
        }
      }
    }
  };
  spfa();
  cout << *max_element(happy.begin(), happy.end()) << '\n';
  return 0;
}