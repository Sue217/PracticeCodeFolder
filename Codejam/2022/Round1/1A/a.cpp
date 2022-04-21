/**
 *    author:  tourist
 *    created: 09.04.2022 04:59:38       
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
    string s;
    cin >> s;                   
    string t = "";
    for (int i = (int) s.size() - 1; i >= 0; i--) {
      t = min(s[i] + t, s[i] + (s[i] + t));
    }
    cout << t << '\n';
  }
  return 0;
}
