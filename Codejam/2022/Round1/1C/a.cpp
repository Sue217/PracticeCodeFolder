/**
 *    author: subobo
 *    created: 30.04.2022 17:00:18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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
    int n;
    cin >> n;
    vector<vector<string>> first(26);
    vector<vector<string>> last(26);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
    }
  }
  return 0;
}