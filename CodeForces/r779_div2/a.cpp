/**
 *    author: subobo
 *    created: 27.03.2022 22:35:19
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
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pos.push_back(i);
      }
    }
    for (int i = 1; i < (int) pos.size(); i++) {
      if (pos[i] - pos[i - 1] - 1 == 0) {
        ans += 2;
      } else
      if (pos[i] - pos[i - 1] - 1 == 1) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}