/**
 *    author:  tourist
 *    created: 09.04.2022 05:16:45       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      a.push_back((1 << min(29, i)) + max(i - 29, 0));
      cout << a.back();
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    int d = 0;
    vector<int> b;
    for (int x : a) {
      if (d >= 0) {
        b.push_back(x);
        d -= x;
      } else {
        d += x;
      }
    }
    for (int i = 0; i < (int) b.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << b[i];
    }
    cout << endl;
  }
  return 0;
}
