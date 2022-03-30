/**
 *    author: subobo
 *    created: 30.03.2022 00:06:46
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
  vector<bool> sq(m * m * 2 + 1);
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      sq[i * i + j * j] = true;
    }
  }
  vector<pair<int, int>> p;
  for (int a = 0; a <= m * m - n + 1; a++) {
    for (int b = 1; a + (n - 1) * b <= m * m * 2; b++) {
      bool ok = true;
      for (int c = 0; c < n; c++) {
        if (!sq[a + b * c]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        p.emplace_back(a, b);
      }
    }
  }
  sort(p.begin(), p.end(), [&](auto a, auto b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });
  if (p.size() == 0) {
    cout << "NONE" << '\n';
  } else {
    for (auto it : p) {
      cout << it.first << " " << it.second << '\n';
    }
  }
  return 0;
}