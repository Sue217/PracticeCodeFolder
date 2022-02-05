/**
 *    author: subobo
 *    created: 05.02.2022 23:06:48
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
    vector<int> one(n + 1), two(n + 1), pre_two(n + 1), suf_one(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> one[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> two[i];
      pre_two[i] = pre_two[i - 1] + two[i];
    }
    for (int i = n; i >= 1; i--) {
      suf_one[i] = suf_one[i + 1] + one[i];
    }
    int bob = (int) 2e9;
    for (int i = 1; i <= n; i++) {
      bob = min(bob, max(suf_one[i + 1], pre_two[i - 1]));
    }
    cout << bob << '\n';
  }
  return 0;
}