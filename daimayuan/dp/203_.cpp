/**
 *    author: subobo
 *    created: 10.03.2022 23:07:24
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

const long long inf = 1ll << 60;

vector<pair<int, int>> item[40];
long long f[1010], g[1010];
int n, W;

void solve() {
  int s = 0;
  for (int i = 0; i <= 30; i++) item[i].clear();
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    int lev = __builtin_ctz(w);
    w >>= lev;
    item[lev].push_back({w, v});
    s += w;
  }
  for (int i = 0; i <= s; i++) f[i] = -inf;
  f[0] = 0;
  for (int i = 30; i >= 0; i--) {
    debug(1, i);
    for (int i = 0; i <= s; i++) {
      debug(2, i);
      g[i] = f[i];
      f[i] = -inf;
    }
    int d = (W >> i) & 1;
    for (int i = 0; i <= s; i++) {
      debug(3, i);
      f[min(s * i + d, s)] = max(f[min(s * i + d, s)], g[i]);
    }
    for (int i = s - 1; i >= 0; i--) {
      debug(4, i);
      f[i] = max(f[i], f[i + 1]);
    }
    for (auto p : item[i]) {
      for (int i = p.first; i <= s; i++) {
        debug(5, i);
        f[i - p.first] = max(f[i - p.first], f[i] + p.second);
      }
    }
  }
  debug("Done");
  cout << f[0] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    cin >> n >> W;
    if (n == -1 && W == -1) {
      break;
    }
    solve();
  }
  return 0;
}