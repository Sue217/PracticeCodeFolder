/**
 *    author:  tourist
 *    created: 02.04.2022 02:03:06       
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
    cout << "Case #" << qq << ": ";
    const int M = (int) 1e6;
    vector<int> a(4, M);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        int x;
        cin >> x;
        a[j] = min(a[j], x);
      }
    }
    int s = accumulate(a.begin(), a.end(), 0);
    if (s < M) {
      cout << "IMPOSSIBLE" << '\n';
    } else {
      for (int i = 0; i < 4; i++) {
        int take = min(s - M, a[i]);
        a[i] -= take;
        s -= take;
      }
      for (int i = 0; i < 4; i++) {
        cout << a[i] << " \n"[i == 3];
      }
    }
  }
  return 0;
}
