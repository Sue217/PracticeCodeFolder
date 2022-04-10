/**
 *    author: subobo
 *    created: 10.04.2022 15:03:30
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
  string t;
  cin >> t;
  int hh = stoi(t.substr(0, 2));
  int mm = stoi(t.substr(3, 2));
  if (hh <= 12) {
    cout << "Only " << t << ".  Too early to Dang." << '\n';
  } else {
    if (mm > 0) {
      for (int i = 0; i <= hh - 12; i++) {
        cout << "Dang";
      }
    } else {
      for (int i = 0; i < hh - 12; i++) {
        cout << "Dang";
      }
    }
    cout << '\n';
  }
  return 0;
}