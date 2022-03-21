/**
 *    author: subobo
 *    created: 29.01.2022 17:32:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> left, right;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'l') {
      left.emplace_back(i + 1);
    } else {
      right.emplace_back(i + 1);
    }
  }
  for (int it : right) {
    cout << it << '\n';
  }
  reverse(left.begin(), left.end());
  for (int it : left) {
    cout << it << '\n';
  }
  return 0;
}