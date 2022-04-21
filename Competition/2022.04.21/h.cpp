#include <bits/stdc++.h>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  const int N = 10010000;
  vector<int> prime;
  bitset<N + 1> used;
  for (int d = 2; d <= N; d++) {
    if (used[d] == 0) prime.push_back(d);
    for (int cc = 0; prime[cc] <= N / d; cc++) {
      used.set(prime[cc] * d);
      if (d % prime[cc] == 0) break;
    }
  }
  used.reset();
  for (int i = 0; i < (int) prime.size(); i++) {
    used.set(prime[i]);
  }
  int ans = 0;
  for (int i = m; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (used[i] && used[j] && used[k] && used[i * j + k] && used[j * k + i] && used[k * i + j]) {
          ans += 1;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}