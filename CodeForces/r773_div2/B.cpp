/**
 *    author: subobo
 *    created: 23.02.2022 18:48:56
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
    set<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    int len = (int) a.size();
    for (int i = 1; i <= n; i++) {
      if (i <= len) {
        cout << len << " ";
      } else {
        cout << i << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}