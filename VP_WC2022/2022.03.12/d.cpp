/**
 *    author: subobo
 *    created: 12.03.2022 16:33:28
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
  int n, k;
  cin >> n >> k;
  vector<long long> s(1, 0);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    a *= a;
    s.push_back(a + s.back());
  }
  long long per = (long long) round(s.back() / k);
  int l = 1;
  long long ans = 0;
  for (int r = 1; r <= n; r++) {
    if (s[r] - s[l - 1] > per) {
      // debug(l, r);
      ans = max(ans, s[r - 1] - s[l - 1]);
      l = r;
    }
  }
  // debug(l);
  ans = max(ans, s.back() - s[l - 1]);
  cout << ans << '\n';
  return 0;
}