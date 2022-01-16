/**
 *    author: subobo
 *    created: 16.01.2022 13:23:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<int> w(n + 1), v(n + 1);
  int root = -1;
  for (int i = 1; i <= n; i++) {
    int index;
    cin >> v[i] >> w[i] >> index;
    if (index == -1) {
      root = i;
    } else {
      Add(index, i);
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  function<void(int)> Dfs = [&](int u) {
    for (int i = h[u]; ~i; i = ne[i]) { // loop groups
      int son = e[i];
      Dfs(son);
      for (int j = m - v[u]; j >= 0; j--) { // loop volume
        for (int k = 0; k <= j; k++) { // loop decisions
          dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
        }
      }
    }
    // push u into package
    for (int i = m; i >= v[u]; i--) {
      dp[u][i] = dp[u][i - v[u]] + w[u];
    }
    // clear bad conditions
    for (int i = 0; i < v[u]; i++) {
      dp[u][i] = 0;
    }
  };
  Dfs(root);
  cout << dp[root][m] << '\n';
  return 0;
}

/**
 *    author: subobo
 *    created: 16.01.2022 13:23:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<int> w(n + 1), v(n + 1);
  int root = -1;
  for (int i = 1; i <= n; i++) {
    int index;
    cin >> v[i] >> w[i] >> index;
    if (index == -1) {
      root = i;
    } else {
      Add(index, i);
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  function<void(int)> Dfs = [&](int u) {
    for (int i = v[u]; i <= m; i++) {
      dp[u][i] = w[u];
    }
    for (int i = h[u]; ~i; i = ne[i]) {
      int son = e[i];
      Dfs(son);
      for (int j = m; j >= v[u]; j--) {
        for (int k = 0; k <= j - v[u]; k++) {
          dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
        }
      }
    }
  };
  Dfs(root);
  cout << dp[root][m] << '\n';
  return 0;
}
