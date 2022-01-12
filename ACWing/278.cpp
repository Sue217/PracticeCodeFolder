/**
 *    author: subobo
 *    created: 12.01.2022 13:19:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> can(m + 1);
  can[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = m; j >= x; j--) {
      can[j] = can[j] + can[j - x];
    }
  }
  cout << can[m] << '\n';
  return 0;
}
