/**
 *    author: subobo
 *    created: 20.02.2022 14:42:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& in : a) {
      cin >> in;
    }
    int ans = 0;
    for (int it : a) {
      if (it == 1 || it == 3) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}