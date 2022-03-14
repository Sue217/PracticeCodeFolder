/**
 *    author: subobo
 *    created: 14.03.2022 09:01:44
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
  priority_queue<int, vector<int>, greater<int>> pque;
  vector<pair<int, int>> cost;
  for (int i = 0; i < n; i++) {
    int d, p;
    cin >> d >> p;
    if (d == 0) {
      continue;
    }
    cost.emplace_back(d, p);
  }
  sort(cost.begin(), cost.end(), [&](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  n = (int) cost.size();
  for (int i = 0; i < n; i++) {
    if (cost[i].first > (int) pque.size()) {
      pque.push(cost[i].second);
    } else {
      if (pque.top() < cost[i].second) {
        pque.pop();
        pque.push(cost[i].second);
      }
    }
  }
  long long ans = 0;
  while (!pque.empty()) {
    ans += 1ll * pque.top();
    pque.pop();
  }
  cout << ans << '\n';
  return 0;
}