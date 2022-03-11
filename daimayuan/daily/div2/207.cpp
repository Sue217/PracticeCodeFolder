/**
 *    author: subobo
 *    created: 11.03.2022 21:53:53
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> f(1, 0);
  int one = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      one += 1;
    }
    f.push_back(one);
  }
  int m = (int) f.size();
  vector<long long> cnt(one + 1);
  for (int l = 1, r = 1; r < m; ) {
    while (f[r] - f[l - 1] <= k) {
      r += 1;
    }
    while (f[l - 1] == f[r] - k) {
      l += 1;
      cnt[f[r]] += 1;
    }
  }
  long long ans = accumulate(cnt.begin(), cnt.end(),0ll);
  cout << ans << '\n';
  return 0;
}