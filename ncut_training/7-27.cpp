/**
 *    author: subobo
 *    created: 01.02.2022 21:28:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  map<string, int> cnt;
  string ans;
  for (int i = 0; i < n; i++) {
    for (int j = n - i; j >= 1; j--) {
      string ss = s.substr(i, j);
      if (cnt.count(ss) != 0) {
        if (ans.size() < ss.size()) {
          ans = ss;
          break;
        }
      }
      cnt[ss] += 1;
    }
  }
  cout << s << '\n';
  if (ans == "") {
    cout << "NULL" << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}