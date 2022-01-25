/**
 *    author: subobo
 *    created: 25.01.2022 18:51:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<long long> a(n);
    for (auto& in : a) {
      cin >> in;
    }
    sort(a.begin(), a.end());
    auto check = [&](long long x) {
      long long sum = 0;
      for (int i = n / 2; i < n; i++) {
        if (x > a[i]) {
          sum += (x - a[i]);
          if (sum > m) {
            return false;
          }
        }
      }
      return true;
    };
    long long low = a[n / 2], high = a[n / 2] + m;
    while (low <= high) {
      long long mid = (high + low) / 2;
      if (check(mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << low - 1 << '\n';
  }
  return 0;
}