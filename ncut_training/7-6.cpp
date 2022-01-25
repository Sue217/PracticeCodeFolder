/**
 *    author: subobo
 *    created: 23.01.2022 20:15:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> tree(n + 1);
  for (int i = 1; i <= n; i++) {
    int left, right;
    cin >> left >> right;
    tree[i].first = left;
    tree[i].second = right;
  }
  function<void(int)> Dfs = [&](int p) {
    if (p == 0) {
      return;
    }
    cout << p << " ";
    Dfs(tree[p].first);
    Dfs(tree[p].second);
  };
  Dfs(1);
  cout << '\n';
  return 0;
}