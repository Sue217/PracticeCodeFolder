/**
 *    author: subobo
 *    created: 06.03.2022 22:51:57
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
    long long sum = accumulate(a.begin(), a.end(), 0ll) - a.back();
    long long ans = 0;
    if (a.back() == 0) {
      ans = 0;
    } else
    if (sum >= a.back()) {
      ans = 1;
    } else {
      ans = a.back() - sum;
    }
    cout << ans << '\n';
  }
  return 0;
}