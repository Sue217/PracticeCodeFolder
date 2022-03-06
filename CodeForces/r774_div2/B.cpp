/**
 *    author: subobo
 *    created: 05.03.2022 20:47:05
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
    vector<long long> a(n);
    for (auto& in : a) {
      cin >> in;
    }
    sort(a.begin(), a.end());
    if (a.size() < 3) {
      cout << "NO" << '\n';
      continue;
    }
    long long L = a[0], R = 0;
    bool ok = true;
    for (int i = 1, j = n - 1; i < j; i++, j--) {
      L += a[i];
      R += a[j];
      if (L < R) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}