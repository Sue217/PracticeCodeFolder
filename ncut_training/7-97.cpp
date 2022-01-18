/**
 *    author: subobo
 *    created: 18.01.2022 21:03:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> node(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> node[i];
  }
  vector<int> tree(n + 1);
  int id = 1;
  function<void(int)> Dfs = [&](int u) {
    if (u > n) {
      return;
    }
    Dfs(u * 2);
    Dfs(u * 2 + 1);
    tree[u] = node[id++];
  };
  Dfs(1);
  for (int it = 1; it < n; it++) {
    cout << tree[it] << " ";
  }
  cout << tree[n] << '\n';
  return 0;
}