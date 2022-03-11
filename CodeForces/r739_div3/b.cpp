/**
 *    author: subobo
 *    created: 11.03.2022 14:03:41
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
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long has = (long long) abs(a - b) * 2;
    // debug(has);
    if (c > has || b > has || a > has) {
      cout << -1 << '\n';
      continue;
    }
    // debug(c + has / 2, has + 1);
    long long ans = (long long) (c + has / 2) % has;
    if (ans == 0) {
      ans = has;
    }
    cout << ans << '\n';
  }
  return 0;
}