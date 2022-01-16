/**
 *    author: subobo
 *    created: 16.01.2022 21:47:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0, cnt = 0, t = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= t) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 1;
    }
    t = x;
  }
  ans = max(ans, cnt);
  cout << ans << '\n';
  return 0;
}