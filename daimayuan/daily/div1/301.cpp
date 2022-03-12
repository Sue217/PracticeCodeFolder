/**
 *    author: subobo
 *    created: 12.03.2022 21:08:26
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
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x - 1 >= 0 && m.count(x - 1) != 0) {
      m[x] = m[x - 1] + 1;
    } else {
      m[x] = 1;
    }
  }
  int ans = 0, len = 0;
  for (auto [v, u] : m) {
    // debug(v, u);
    if (u > len) {
      len = u;
      ans = v;
    }
  }
  cout << len << '\n';
  for (int i = ans - len + 1; i <= ans; i++) {
    cout << i << " \n"[i == ans];
  }
  return 0;
}