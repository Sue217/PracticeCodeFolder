/**
 *    author: subobo
 *    created: 09.02.2022 15:22:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<long long> mi(15), dp(15);
  mi.front() = 1ll;
  for (int i = 1; i < 15; i++) {
    dp[i] = dp[i - 1] * 10ll + mi[i - 1];
    mi[i] = mi[i - 1] * 10ll;
  }
  long long a, b;
  while (cin >> a >> b, a || b) {
    if (a > b) {
      swap(a, b);
    }
    vector<long long> left(10, 0), right(10, 0);
    auto solve = [&](long long n, vector<long long>& ans) {
      vector<long long> v(1, 0);
      long long t = n;
      while (n) {
        v.emplace_back(n % 10ll);
        n /= 10ll;
      }
      for (int i = (int) v.size() - 1; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
          ans[j] += dp[i - 1] * v[i];
        }
        for (int j = 0; j < (int) v[i]; j++) {
          ans[j] += mi[i - 1];
        }
        t -= v[i] * mi[i - 1];
        ans[v[i]] += t + 1;
        ans[0] -= mi[i - 1];
      }
    };
    solve(b, right);
    solve(a - 1, left);
    for (int it = 0; it < 10; it++) {
      cout << right[it] - left[it] << " \n"[it == 9];
    }
  }
  return 0;
}