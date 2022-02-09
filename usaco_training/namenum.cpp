/**
 *    author: subobo
 *    created: 09.02.2022 16:29:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string num;
  cin >> num;
  string name;
  map<char, int> mp;
  char ch = 'A';
  for (int i = 2; i <= 9; i++) {
    for (int j = 0; j < 3; j++) {
      if (ch + j == 'Q') {
        ch += 1;
      }
      mp[ch + j] = i;
    }
    ch += 3;
  }
  bool ok = true;
  set<string> sst;
  while (cin >> name) {
    string ans = "";
    for (char c : name) {
      ans += mp[c] + '0';
    }
    if (ans == num) {
      ok = false;
      sst.insert(name);
    }
  }
  if (ok) {
    cout << "NONE\n";
  } else {
    for (auto it : sst) {
      cout << it << '\n';
    }
  }
  return 0;
}