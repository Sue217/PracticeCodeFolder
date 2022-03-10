/**
 *    author: subobo
 *    created: 09.03.2022 14:53:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 17;
  vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(2, vector<long long>(10, -1)));
  function<int(int, int, int)> DP = [&](int re, int st, int last)->long long {
    if (re <= 0) {
      return st;
    }
    long long& ans = dp[re][st][last];
    if (ans != -1) {
      return ans;
    }
    ans = 0;
    for (int i = max(0, last - 2); i < min(9, last + 2); i++) {
    }
  };
  auto calc = [&](long long x)->long long {
    ++x;
    vector<int> a;
    while (x) {
      a.push_back(x % 10);
      x /= 10;
    }
    a.push_back(0);
    reverse(a.begin(), a.end());
    long long ans = 0;
    int m = (int) a.size() - 1;
    for (int i = 1; i <= m - 1; i++) {
      for (int j = 1; j < 10; j++) {
        ans += DP(i - 1, 0, j);
      }
    }
  };
  long long L, R;
  cin >> L >> R;
  cout << calc(R) - calc(L - 1) << '\n';
  return 0;
}