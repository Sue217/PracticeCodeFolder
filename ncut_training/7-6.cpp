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
  vector<int> tree(n * 2 + 2);
  for (int i = 1; i <= n; i++) {
    int left, right;
    cin >> left >> right;
    if (tree[i] == 0) {
      tree[i] = i;
    }
    tree[i * 2] = left;
    tree[i * 2 + 1] = right;
  }
  function<void(int)> Dfs = [&](int p) {
    if (p > n || tree[p] == 0) {
      return;
    }
    cout << tree[p] << " ";
    Dfs(p * 2);
    Dfs(p * 2 + 1);
  };
  Dfs(1);
  cout << '\n';
  return 0;
}