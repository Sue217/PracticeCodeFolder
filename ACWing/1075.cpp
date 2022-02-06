/**
 *    author: subobo
 *    created: 06.02.2022 17:45:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> dir;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n / i; j++) {
      dir[i * j] += i;
    }
  }
  vector<int> h(n * 2 + 1, -1), e(n * 2 + 1), ne(n * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<bool> root(n + 1);
  for (int i = 1; i <= n; i++) {
    if (dir.count(i) != 0) {
      if (i > dir[i]) {
        Add(dir[i], i);
        root[i] = true;
      }
    }
  }
  int ans = 0;
  function<int(int)> Dfs = [&](int u) {
    int d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      int d = Dfs(j) + 1;
      if (d > d1) {
        d2 = d1;
        d1 = d;
      } else
      if (d > d2) {
        d2 = d;
      }
    }
    ans = max(ans, d1 + d2);
    return d1;
  };
  for (int i = 1; i <= n; i++) {
    if (!root[i]) {
      Dfs(i);
    }
  }
  cout << ans << '\n';
  return 0;
}