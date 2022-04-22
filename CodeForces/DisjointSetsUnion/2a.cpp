/**
 *    author: subobo
 *    created: 22.04.2022 20:54:37
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> get = [&](int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
  };
  while (m--) {
    char c;
    cin >> c;
    int z;
    cin >> z;
    --z;
    if (c == '-') {
      p[z] = get(z + 1);
    } else {
      z = get(z);
      cout << (z == n ? -1 : z + 1) << '\n';
    }
  }
  return 0;
}