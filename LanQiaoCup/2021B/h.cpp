/**
 *    author: subobo
 *    created: 08.04.2022 14:54:23
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
  constexpr int N = 100;
  vector f(N, vector<unsigned long long>(N));
  for (int i = 0; i < N; i++) {
    f[i][1] = 1;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
  }
  int idx = 2;
  map<unsigned long long, int> s;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (f[i][j] == 0) break;
      if (s.count(f[i][j]) == 0) {
        s[f[i][j]] = idx;
      }
      ++idx;
    }
  }
  unsigned long long n;
  cin >> n;
  cout << s[n] << '\n';
  return 0;
}