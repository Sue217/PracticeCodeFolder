/**
 *    author: subobo
 *    created: 25.04.2022 00:42:13
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
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, p;
    cin >> n >> p;
    set<long long> s, prev;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      prev = s;
      s.clear();
      long long delta = (long long) 1e31;
      long long last = 0;
      for (int j = 0; j < p; j++) {
        long long x;
        cin >> x;
        s.insert(x);
        sum += (long long) abs(x - last);
        last = x;
        if (!prev.empty()) {
          delta = max(0ll, min({delta, *prev.lower_bound(x) - x, (long long) abs(x - *max_element(prev.begin(), prev.end()))}));
        }
      }
      if (i != 0) {
        sum -= delta;
      }
    }
    cout << sum << '\n';
  }
  return 0;
}