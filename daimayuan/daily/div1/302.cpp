/**
 *    author: subobo
 *    created: 13.03.2022 08:51:44
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
  int n;
  cin >> n;
  vector<pair<int, int>> cost;
  for (int i = 0; i < n; i++) {
    int d, p;
    cin >> d >> p;
    cost.emplace_back(d, p);
  }
  sort(cost.begin(), cost.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  int ddl = 0, reward = 0;
  for (auto p : cost) {
    if (ddl != p.first) {
      reward += p.second;
      ddl = p.first;
    }
  }
  cout << reward << '\n';
  return 0;
}