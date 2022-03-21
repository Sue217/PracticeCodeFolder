/**
 *    author: subobo
 *    created: 16.02.2022 14:08:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, s, c;
  cin >> m >> s >> c;
  vector<pair<int, int>> stall(1, make_pair(0, 0));
  vector<int> v(c);
  for (int& in : v) {
    cin >> in;
  }
  sort(v.begin(), v.end());
  int st = v.front(), ed = v.back();
  for (int it : v) {
    stall.emplace_back(it, it - stall.back().first);
  }
  if (c > 0) {
    stall[1].second = 0;
  }
  sort(stall.begin(), stall.end(), [](const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
  });
  int ans = 0;
  for (int i = 0; i < m - 1; i++) {
    ans += stall[i].second - 1;
  }
  ans = ed - st + 1 - ans;
  if (m >= c) {
    ans = c;
  }
  cout << ans << '\n';
  return 0;
}