/**
 *    author: subobo
 *    created: 19.01.2022 09:36:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<string> name;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    name.insert(s);
  }
  int m;
  cin >> m;
  map<string, int> mp;
  int average = 0;
  for (int i = 0; i < m; i++) {
    string name;
    int likes;
    cin >> name >> likes;
    average += likes;
    mp[name] = likes;
  }
  average /= m;
  bool ok = true;
  for (auto it : mp) {
    if (it.second > average and name.find(it.first) == name.end()) {
      ok = false;
      cout << it.first << '\n';
    }
  }
  if (ok) {
    cout << "Bing Mei You" << '\n';
  }
  return 0;
}