/**
 *    author: subobo
 *    created: 07.02.2022 23:15:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int m = n - 1;
    vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), ne(m * 2 + 1);
    int idx = 0;
    auto Add = [&](int a, int b) {
      e[idx] = b;
      ne[idx] = h[a];
      h[a] = idx++;
    };
    vector<bool> has_father(n + 1);
    for (int i = 0; i < n; i++) {
      int from, to, num;
      scanf("%d:(%d)", &from, &num);
      for (int j = 0; j < num; j++) {
        cin >> to;
        Add(from, to);
        has_father[to] = true;
      }
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    int root = -1;
    for (int id = 0; id < n; id++) {
      if (!has_father[id]) {
        root = id;
        break;
      }
    }
    function<void(int)> Dfs = [&](int u) {
      dp[u][1] = 1;
      for (int id = h[u]; id != -1; id = ne[id]) {
        int son = e[id];
        Dfs(son);
        dp[u][0] += dp[son][1];
        dp[u][1] += min(dp[son][0], dp[son][1]);
      }
    };
    Dfs(root);
    cout << min(dp[root][0], dp[root][1]) << '\n';
  }
  return 0;
}