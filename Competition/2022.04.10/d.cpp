/**
 *    author: subobo
 *    created: 10.04.2022 15:56:22
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
  string s;
  int x = 0;
  while (cin >> s && s != ".") {
    string a, b;
    if (++x == 2) {
      a = s;
    } else if (x == 14) {
      b = s;
    }
    if (x < 2) cout << "Momo... No one is for you ..." << '\n';
    else if (x < 14) cout << a << "is the only one for you..." << '\n';
    else cout << a << " and " << b << " are inviting you to dinner..." << '\n';
  }
  return 0;
}