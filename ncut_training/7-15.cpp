/**
 *    author: subobo
 *    created: 26.01.2022 11:45:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s) {
      int t;
      if (c == 'y') {
        t = 0;
      } else {
        t = 1;
      }
      ans = ans * 2 + t;
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}