/**
 *    author: subobo
 *    created: 28.01.2022 21:21:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  int ones = 0;
  for (int& in : seq) {
    cin >> in;
    if (in == 1) {
      ones += 1;
    }
  }
  int ans = -123, cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        if (seq[k] == 0) {
          cnt += 1;
        } else {
          cnt -= 1;
        }
      }
      if (ans <= cnt) {
        ans = cnt;
      }
      cnt = 0;
    }
  }
  cout << ans + ones << '\n';
  return 0;
}