/**
 *    author: subobo
 *    created: 23.01.2022 21:52:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1));
  int out = 1, line = n;
  for (int i = 1; i <= n; i++, line--) {
    for (int j = 1; j <= line; j++) {
      g[j][i] = out++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[i][j]) {
        cout << setw(4) << g[i][j];
      }
    }
    cout << '\n';
  }
  return 0;
}