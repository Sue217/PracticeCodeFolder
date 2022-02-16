/**
 *    author: subobo
 *    created: 16.02.2022 13:32:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> milk;
  for (int i = 0; i < m; i++) {
    int p, a;
    cin >> p >> a;
    milk.emplace_back(p, a);
  }
  sort(milk.begin(), milk.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  int tot = n, ans = 0;
  for (auto it : milk) {
    if (tot <= 0) {
      break;
    }
    int cnt = it.second <= tot ? it.second : tot;
    tot -= cnt;
    ans += it.first * cnt;
  }
  cout << ans << '\n';
  return 0;
}