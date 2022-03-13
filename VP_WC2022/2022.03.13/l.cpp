/**
 *    author: subobo
 *    created: 13.03.2022 20:35:30
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
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    vector<int> que(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> que[i];
    }
    stack<int> s;
    bool ok = true;
    int req = 1;
    for (int i = 1; i <= n; i++) {
      if (que[i] == req) {
        ++req;
        while (!s.empty() && s.top() == req) {
          s.pop();
          ++req;
        }
        continue;
      }
      while (!s.empty() && s.top() == que[i]) {
        s.pop();
        if (++req == que[i]) {
          ok = false;
          ++req;
          break;
        }
      }
      if (ok) {
        if ((int) s.size() == m) {
          break;
        }
        s.push(que[i]);
      }
      while (!s.empty() && s.top() == req) {
        ++req;
        s.pop();
      }
    }
    if (s.empty()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}