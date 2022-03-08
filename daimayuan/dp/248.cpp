/**
 *    author: subobo
 *    created: 07.03.2022 17:16:54
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 17;
vector<vector<vector<vector<long long>>>> dp(N, vector<vector<vector<long long>>>(2, vector<vector<long long>>(10, vector<long long>(4, -1))));

inline long long DP(int re, int st, int last, int len) {
  if (re <= 0) {
    return st;
  }
  long long& ans = dp[re][st][last][len];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int i = 0; i < 10; i++) {
    int inc = (i > last) ? min(len + 1, 3) : 1;
    ans += DP(re - 1, st | (inc == 3), i, inc);
  }
  return ans;
}

inline long long calc(long long x) {
  x += 1;
  vector<int> a;
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  a.push_back(0);
  reverse(a.begin(), a.end());
  int m = (int) a.size() - 1;
  long long ans = 0;
  for (int i = 1; i <= m - 1; i++) {
    for (int j = 1; j < 10; j++) {
      ans += DP(i - 1, 0, j, 1);
    }
  }
  int st = 0, last = 0, len = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = (i == 1) ? 1 : 0; j < a[i]; j++) {
      int inc = (j > last) ? min(len + 1, 3) : 1;
      ans += DP(m - i, st | (inc == 3), j, inc);
    }
    len = (a[i] > last) ? min(len + 1, 3) : 1;
    st |= (len == 3);
    last = a[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long L, R;
  cin >> L >> R;
  long long ans = calc(R) - calc(L - 1);
  cout << ans << '\n';
  return 0;
}