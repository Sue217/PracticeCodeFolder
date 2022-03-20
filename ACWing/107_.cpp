/**
 *    author: subobo
 *    created: 20.03.2022 17:44:52
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
  while (cin >> n, n != 0) {
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    function<long long(int, int)> merge = [&](int L, int R)->long long {
      if (L >= R) {
        return 0;
      }
      int mid = (L + R) / 2;
      long long ans = merge(L, mid) + merge(mid + 1, R);
      int low = L, high = mid + 1;
      vector<long long> tmp;
      while (low <= mid && high <= R) {
        if (a[low] <= a[high]) {
          tmp.push_back(a[low]);
          ++low;
        } else {
          ans += mid - low + 1;
          tmp.push_back(a[high]);
          ++high;
        }
      }
      while (low <= mid) {
        tmp.push_back(a[low]);
        ++low;
      }
      while (high <= R) {
        tmp.push_back(a[high]);
        ++high;
      }
      for (int i = L, j = 0; i <= R; i++, j++) {
        assert(j <= R - L + 1);
        a[i] = tmp[j];
      }
      return ans;
    };
    long long ans = merge(0, n - 1);
    cout << ans << '\n';
  }
  return 0;
}