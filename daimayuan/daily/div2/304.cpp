/**
 *    author: subobo
 *    created: 15.03.2022 22:11:16
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> div;
    for (int i = 1; i < n; i++) {
      div.push_back(a[i] - a[i - 1]);
    }
    int ans = 0;
    for (int it : div) {
      if (it != 0) {
        ans = gcd(ans, it);
      }
    }
    if (ans == 0) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
  return 0;
}