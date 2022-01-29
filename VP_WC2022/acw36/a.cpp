/**
 *    author: subobo
 *    created: 29.01.2022 19:00:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<char> ans;
  for (char& c : s) {
    if (c >= 'A' && c <= 'Z') {
      c += 32;
    }
    if (!(c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i')) {
      ans.emplace_back('.');
      ans.emplace_back(c);
    }
  }
  for (char c : ans) {
    cout << c;
  }
  cout << '\n';
  return 0;
}