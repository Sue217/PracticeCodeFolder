/**
 *    author: subobo
 *    created: 23.04.2022 10:05:19
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
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  function<int(int)> get = [&](int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
  };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --x;
    x = get(x);
    cout << x + 1 << " \n"[i == n - 1];
    p[x] = get((x + 1) % n);
  }
  return 0;
}