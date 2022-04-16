/**
 *    author: subobo
 *    created: 16.04.2022 14:33:10
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
  int n;
  cin >> n;
  vector<int> a(n);
  const int M = 22;
  const int N = 1 << M;
  vector<int> f(N, N + N);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]] = min(f[a[i]], i);
  }
  for  (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (j >> i & 1) {
        f[j] = min(f[j], f[j - (1 << i)]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = N - 1 - a[i];
    cout << (f[a[i]] > N ? -1 : f[a[i]] + 1) << " \n"[i == n - 1];
  }
  cerr << "time: " << clock() / 1000 << " ms" << '\n';
  return 0;
}