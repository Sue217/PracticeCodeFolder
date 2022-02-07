/**
 *    author: subobo
 *    created: 06.02.2022 22:33:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s, revs;
    cin >> n >> m >> s;
    int ans = 1;
    revs = s;
    reverse(revs.begin(), revs.end());
    if (m >= 1) {
      if (s != revs) {
        ans = 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}