/**
 *    author: subobo
 *    created: 05.03.2022 20:40:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, s;
    cin >> n >> s;
    long long ans = s / (n * n);
    cout << ans << '\n';
  }
  return 0;
}