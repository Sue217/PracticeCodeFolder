/**
 *    author: subobo
 *    created: 11.02.2022 15:01:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> sum(1, 0);
  for (int i = 1; i <= n; i++) {
    int e;
    cin >> e;
    sum.emplace_back(sum.back() + e);
  }
  deque<int> mono(1, 0);
  vector<long long> f(n + 1, 0);
  auto g = [&](int x)->long long {
    if (x == 0) {
      return 0;
    }
    return f[x - 1] - sum[x];
  };
  for (int it = 1; it <= n; it++) {
    if (mono.front() < it - k) {
      mono.pop_front();
    }
    f[it] = max(f[it - 1], g(mono.front()) + sum[it]);
    while (!mono.empty() && g(mono.back()) <= g(it)) {
      mono.pop_back();
    }
    mono.push_back(it);
  }
  cout << f[n] << '\n';
  return 0;
}