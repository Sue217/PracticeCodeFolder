/**
 *    author: subobo
 *    created: 25.03.2022 12:27:30
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
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> que(n);
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --b;
    while (!que[b].empty() && que[b].top().first <= a) {
      v[b] += que[b].top().second;
      que[b].pop();
    }
    if (v[b] >= d) {
      v[b] -= d;
      que[b].emplace(a + c, d);
      cout << v[b] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}