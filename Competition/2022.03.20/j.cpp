/**
 *    author: subobo
 *    created: 20.03.2022 20:17:39
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
  int n, m;
  cin >> n >> m;
  --m;
  vector<bool> a(n);
  int check = 0, has = n;
  while (has > 1) {
    for (int i = 0; i < n; i++) {
      if (has == 1) {
        break;
      }
      if (a[i]) {
        continue;
      }
      if (check == m) {
        a[i] = true;
        has -= 1;
        check = 0;
      } else {
        check += 1;
      }
    }
  }
  for (int p = 0; p < n; p++) {
    if (!a[p]) {
      cout << p << '\n';
      break;
    }
  }
  return 0;
}