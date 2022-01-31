/**
 *    author: subobo
 *    created: 31.01.2022 11:07:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> height(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }
  vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), w(m * 2 + 1), ne(m * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b, int c) {
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int w = height[u] - height[v];
    if (w > 0) {
      Add(u, v, w);
      Add(v, u, -2 * w);
    } else {
      Add(u, v, 2 * w);
      Add(v, u, -w);
    }
  }
  vector<long long> hp(n + 1, -(int) 2e9);
  vector<bool> vis(n + 1);
  queue<int> q;
  q.push(1);
  hp[1] = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    vis[t] = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (hp[j] < hp[t] + w[i]) {
        hp[j] = hp[t] + w[i];
        if (!vis[j]) {
          vis[j] = true;
          q.push(j);
        }
      }
    }
  }
  cout << *max_element(hp.begin(), hp.end()) << '\n';
  return 0;
}