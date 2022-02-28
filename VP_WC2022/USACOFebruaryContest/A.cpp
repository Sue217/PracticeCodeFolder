/**
 *    author: subobo
 *    created: 28.02.2022 10:20:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    auto f = std::move(a);
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
    if (f.size() == 1) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = n; i >= 1; i--) {
      if (pre[n] % i != 0) {
        continue;
      }
      int p = 0;
      bool ok = true;
      int sum = pre[n] / i;
      auto get = [&](int x) {
        int left = x + 1, right = n;
        while (left <= right) {
          int mid = (left + right) / 2;
          int tmp = pre[mid] - pre[p];
          if (tmp == sum) {
            return mid;
          } else
          if (tmp > sum) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
        return -1;
      };
      for (int j = 0; j < i; j++) {
        p = get(p);
        if (p == -1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << n - i << '\n';
        break;
      }
      p = 0;
    }
  }
  return 0;
}