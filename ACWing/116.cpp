/**
 *    author: subobo
 *    created: 03.02.2022 21:17:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> g(4);
  for (int i = 0; i < 4; i++) {
    cin >> g[i];
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < 16; i++) {
    auto backup = g;
    auto Switch = [&](int x, int y) {
      for (int c = 0; c < 4; c++) {
        if (c == y) {
          continue;
        }
        if (backup[x][c] == '-') {
          backup[x][c] = '+';
        } else {
          backup[x][c] = '-';
        }
      }
      for (int l = 0; l < 4; l++) {
        if (l == x) {
          continue;
        }
        if (backup[l][y] == '-') {
          backup[l][y] = '+';
        } else {
          backup[l][y] = '-';
        }
      }
      if (backup[x][y] == '-') {
        backup[x][y] = '+';
      } else {
        backup[x][y] = '-';
      }
    };
    vector<pair<int, int>> path;
    for (int it = 0; it < 4; it++) {
      if ((i >> it) & 1) {
        Switch(0, it);
        path.emplace_back(1, it + 1);
      }
    }
    for (int j = 1; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (backup[j - 1][k] == '+') {
          Switch(j, k);
          path.emplace_back(j + 1, k + 1);
        }
      }
    }
    if (ans.empty() || ans.size() > path.size()) {
      ans.clear();
      ans = path;
    }
  }
  cout << ans.size() << '\n';
  for (auto it : ans) {
    cout << it.first << " " << it.second << '\n';
  }
  return 0;
}