/**
 *    author: subobo
 *    created: 13.03.2022 18:12:51
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  int tt;
  cin >> tt;
  getchar();
  while (tt--) {
    string s;
    getline(cin, s);
    bool ok = true;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == ',' || s[i] == '.') {
        if (i < 3) {
          ok = false;
          continue;
        }
        if (s[i - 3] != 'o' || s[i - 2] != 'n' || s[i - 1] != 'g') {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << "Skipped" << '\n';
      continue;
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ' ' && cnt < 3) {
        ++cnt;
      }
      if (cnt == 3) {
        cnt = i;
        break;
      }
    }
    ++cnt;
    for (int i = 0; i < cnt; i++) {
      cout << s[i];
    }
    cout << "qiao ben zhong." << '\n';
  }
  return 0;
}