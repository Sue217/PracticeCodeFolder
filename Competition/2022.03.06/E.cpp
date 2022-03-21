/**
 *    author: subobo
 *    created: 06.03.2022 18:02:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto is_prime = [&](int x) {
    if (x < 2) {
      return false;
    }
    for (int i = 2; i <= x / i; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };
  long long ans = 0;
  vector<int> x(n);
  for (int& in : x) {
    cin >> in;
  }
  function<void(int, int, int)> Dfs = [&](int choose, int sum, int start) {
    if (choose == k) {
      if (is_prime(sum)) {
        ans += 1;
      }
      return;
    }
    for (int i = start; i < n; i++) {
      Dfs(choose + 1, sum + x[i], i + 1);
    }
  };
  Dfs(0, 0, 0);
  cout << ans << '\n';
  return 0;
}