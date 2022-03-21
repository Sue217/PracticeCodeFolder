/**
 *    author: subobo
 *    created: 21.01.2022 09:35:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> m;
    cout << upper_bound(x.begin(), x.end(), m) - x.begin() - 1 << '\n';
  }
  return 0;
}