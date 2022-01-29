/**
 *    author: subobo
 *    created: 29.01.2022 17:50:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) {
      break;
    }
    vector<int> ance(n + 1);
    vector<bool> marked(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> ance[i];
    }
    char op;
    int x;
    long long ans = 0;
    marked[1] = true;
    for (int i = 0; i < m; i++) {
      cin >> op >> x;
      if (op == 'M') {
        marked[x] = true;
      } else {
        x = ance[x];
        while (!marked[x]) {
          x = ance[x];
        }
        ans += x;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}