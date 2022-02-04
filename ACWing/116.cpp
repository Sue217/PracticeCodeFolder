/**
 *    author: subobo
 *    created: 03.02.2022 23:54:49
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
  for (int i = 0; i < (1 << 16); i++) {
    vector<pair<int, int>> path;
    auto backup = g;
    auto Switch = [&](int x, int y) {
      auto turn = [&](int x, int y) {
        if (backup[x][y] == '-') {
          backup[x][y] = '+';
        } else {
          backup[x][y] = '-';
        }
      };
      for (int i = 0; i < 4; i++) {
        turn(i, y);
        turn(x, i);
      }
      turn(x, y);
    };
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if ((i >> (j * 4 + k)) & 1) {
          Switch(j, k);
          path.emplace_back(j + 1, k + 1);
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (backup[j][k] == '+') {
          ok = false;
          break;
        }
      }
    }
    if (ans.empty() || ok) {
      ans = path;
    }
  }
  cout << ans.size() << '\n';
  for (auto it : ans) {
    cout << it.first << " " << it.second << '\n';
  }
  return 0;
}