/**
 *    author: subobo
 *    created: 26.01.2022 12:08:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string line, pattern = "chi1 huo3 guo1";
  int tt = 0, cnt = 0, where = 0;
  while (getline(cin, line), line != ".") {
    tt += 1;
    for (int i = 0; i < (int) line.size(); i++) {
      if (line.substr(i, 14) == pattern) {
        cnt += 1;
        if (where == 0) {
          where = tt;
        }
        break;
      }
    }
  }
  cout << tt << '\n';
  if (cnt == 0) {
    cout << "-_-#" << '\n';
  } else {
    cout << where << " " << cnt << '\n';
  }
  return 0;
}