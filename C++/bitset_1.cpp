/**
 *    author: subobo
 *    created: 23.02.2022 08:44:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<bool> can(m + 1);
  can[0] = true;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = m; j >= x; j--) {
      if (can[j - x]) {
        can[j] = true;
      }
    }
  }
  // get result does have can[m] O(nm)
  puts(can[m] ? "Yes" : "No");
  // count the number of existing elements O(n)
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (can[i]) {
      cnt += 1;
    }
  }
  cout << cnt << '\n';
  return 0;
}