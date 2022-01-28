/**
 *    author: subobo
 *    created: 28.01.2022 15:52:02
**/
#include <bits/stdc++.h>

using namespace std;

inline void read(__int128& v) {
  v = 0;
  __int128 s = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      s = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = v * 10 + c - '0';
    c = getchar();
  }
}

inline void print(__int128 v) {
  if (v < 0) {
    putchar('-');
    v = -v;
  }
  if (v > 9) {
    print(v / 10);
  }
  putchar(v % 10 + '0');
}

int main() {
  int n;
  cin >> n;
  vector<__int128> node(n + 1);
  for (int i = 1; i <= n; i++) {
    read(node[i]);
  }
  vector<vector<__int128>> dp(n + 1, vector<__int128>(n + 1));
  for (int len = 3; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      dp[l][r] = (__int128) 2e31;
      for (int m = l + 1; m < r; m++) {
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + node[l] * node[m] * node[r]);
      }
    }
  }
  print(dp[1][n]);
  return 0;
}