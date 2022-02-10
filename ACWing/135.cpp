/**
 *    author: subobo
 *    created: 10.02.2022 14:20:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> sum(1, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum.emplace_back(sum.back() + a);
  }
  deque<int> mono(1, 0);
  int ans = -(int) 2e9;
  for (int it = 1; it <= n; it++) {
    if (mono.front() < it - m) {
      mono.pop_front();
    }
    ans = max(ans, sum[it] - sum[mono.front()]);
    while (!mono.empty() && sum[mono.back()] >= sum[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
  }
  cout << ans << '\n';
  return 0;
}