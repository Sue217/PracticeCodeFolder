/**
 *    author: subobo
 *    created: 13.03.2022 18:03:21
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
  getline(cin, s);
  int n = (int) s.size();
  string xs = "";
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '6') {
      if (ptr != 0) {
        if (ptr == 1) {
          xs += '6';
        } else
        if (ptr == 2) {
          xs += '6';
          xs += '6';
        } else
        if (ptr == 3) {
          xs += '6';
          xs += '6';
          xs += '6';
        } else
        if (ptr > 9) {
          xs += '2';
          xs += '7';
        } else
        if (ptr > 3) {
          xs += '9';
        }
        ptr = 0;
      }
      xs += s[i];
    }
    if (s[i] == '6') {
      ++ptr;
    }
  }
  if (ptr != 0) {
    if (ptr == 1) {
      xs += '6';
    } else
    if (ptr == 2) {
      xs += '6';
      xs += '6';
    } else
    if (ptr == 3) {
      xs += '6';
      xs += '6';
      xs += '6';
    } else
    if (ptr > 9) {
      xs += '2';
      xs += '7';
    } else
    if (ptr > 3) {
      xs += '9';
    }
    ptr = 0;
  }
  cout << xs << '\n';
  return 0;
}