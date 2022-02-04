/**
 *    author: subobo
 *    created: 04.02.2022 10:21:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> happy(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> happy[i];
  }
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<bool> has_father(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int father, son;
    cin >> son >> father;
    Add(father, son);
    has_father[son] = true;
  }
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  function<void(int)> Dfs = [&](int u) {
    dp[u][1] = happy[u];
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      Dfs(j);
      dp[u][0] += max(dp[j][0], dp[j][1]);
      dp[u][1] += dp[j][0];
    }
  };
  int root;
  for (int i = 1; i <= n; i++) {
    if (!has_father[i]) {
      root = i;
      break;
    }
  }
  Dfs(root);
  cout << max(dp[root][0], dp[root][1]) << '\n';
  return 0;
}