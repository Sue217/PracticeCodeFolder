/**
 *    author: subobo
 *    created: 31.03.2022 14:48:29
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
  cin >> s;
  s += ' ';
  int n = (int) s.size();
  for (int i = 0; i < n - 1; i++) {
    if (isalpha(s[i])) {
      if (isdigit(s[i + 1])) {
        int t = s[i + 1] - '0';
        for (int j = 0; j < t; j++) {
          cout << s[i];
        }
      } else {
        cout << s[i];
      }
    }
  }
  return 0;
}