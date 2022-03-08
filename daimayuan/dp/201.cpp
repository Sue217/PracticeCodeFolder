/**
 *    author: subobo
 *    created: 08.03.2022 09:20:53
**/
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 17;
  vector<vector<vector<vector<long long>>>> dp(N, vector<vector<vector<long long>>>(2, vector<vector<long long>>(10, vector<long long>(4, -1))));
  function<long long(int, int, int, int)> DP = [&](int re, int st, int last, int len)->long long {
    if (re <= 0) {
      return st;
    }
    long long& ans = dp[re][st][last][len];
    if (ans != -1) {
      return ans;
    }
    ans = 0;
    for (int i = 0; i < 10; i++) {
      int inc = (last < i) ? min(len + 1, 3) : 1;
      ans += DP(re - 1, st | (inc == 3), i, inc);
    }
    return ans;
  };
  auto calc = [&](long long x)->long long {
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
        long long v = DP(i - 1, 0, j, 1);
        ans += v;
        debug(i, j, v);
      }
    }
    int st = 0, last = 0, len = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = (i == 1) ? 1 : 0; j < a[i]; j++) {
        int inc = (last < j) ? min(len + 1, 3) : 1;
        long long v = DP(m - i, st | (inc == 3), j, inc);
        ans += v;
        debug(i, j, v);
      }
      len = (last < a[i]) ? min(len + 1, 3) : 1;
      st |= (len == 3);
      last = a[i];
    }
    return ans;
  };
  long long L, R;
  cin >> L >> R;
  cout << calc(R) - calc(L - 1) << '\n';
  return 0;
}