/**
 *    author: subobo
 *    created: 01.02.2022 18:17:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<string, string> dir;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    dir[b] = a;
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (dir.count(s) != 0) {
      cout << dir[s] << '\n';
    } else {
      cout << "eh" << '\n';
    }
  }
  return 0;
}