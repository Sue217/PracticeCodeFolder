/**
 *    author: subobo
 *    created: 04.02.2022 09:54:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string xa, xb;
  cin >> xa >> xb;
  int n = (int) xa.size(), ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (xa[i] != xb[i]) {
      ans += 1;
      if (xa[i + 1] == 'o') {
        xa[i + 1] = '*';
      } else {
        xa[i + 1] =  'o';
      }
    }
  }
  cout << ans << '\n';
  return 0;
}