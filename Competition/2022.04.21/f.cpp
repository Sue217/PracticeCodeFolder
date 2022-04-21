#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (islower(s[i])) {
        if (islower(s[i + 1])) {
          if (s[i + 1] == s[i] - 1) {
            continue;
          } else {
            ok = false;
            break;
          }
        } else
        if (isupper(s[i + 1])) {
          if (s[i + 1] == 'A' + s[i] - 'a') {
            continue;
          } else {
            ok = false;
            break;
          }
        } else {
          ok = false;
          break;
        }
      } else
      if (isupper(s[i])) {
        if (isupper(s[i + 1])) {
          if (s[i + 1] == s[i] + 1) {
            continue;
          } else {
            ok = false;
            break;
          }
        } else
        if (islower(s[i + 1])) {
          if (s[i + 1] == 'a' + s[i] - 'A') {
            continue;
          } else {
            ok = false;
            break;
          }
        } else {
          ok = false;
          break;
        }
      } else {
        ok = false;
        break;
      }
    }
    cout << (ok ? "Y" : "N") << '\n';
  }
  return 0;
}