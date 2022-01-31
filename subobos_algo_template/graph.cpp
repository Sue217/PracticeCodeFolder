/**
 *    author: subobo
 *    created: 31.01.2022
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class graph {
 public:
  vector<int> h, ne, e, w;
  int idx;
  int n, m;

  graph(int _n, int _m) : n(_n), m(_m) {
    h.assign(m, -1);
    ne.resize(m);
    e.resize(m);
    w.resize(m);
    idx{};
  }

  inline Add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  }

  inline Add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
  }

  inline spfa(int x, int y) {
    vector<bool> vis(n + 1);
    vector<T> v(n + 1, (int) 2e9);
    queue<int> q;
    v[x] = 1;
    q.push(x);
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      vis[t] = false;
      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        if (v[j] > v[t] + w[i]) {
          v[j] = v[t] + w[i];
          if (!vis[j]) {
            vis[j] = true;
            q.push(j);
          }
        }
      }
    }
  }
};