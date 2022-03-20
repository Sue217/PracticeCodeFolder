/**
 *    author: subobo
 *    created: 20.03.2022 19:20:44
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      int start, finish;
      cin >> start >> finish;
      a.emplace_back(start, finish);
    }
    sort(a.begin(), a.end(), [&](auto a, auto b) {return a.second < b.second;});
    int ans = 0;
    int finish = -(int) 1e9;
    for (auto p : a) {
      if (p.first >= finish) {
        ans += 1;
        finish = p.second;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}