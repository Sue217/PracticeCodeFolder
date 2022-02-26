/**
 *    author: subobo
 *    created: 26.02.2022 13:47:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> ma, mi;
  ma.push(0);
  mi.push(0);
  long long ans = 0, sum = 0;
  // max
  for (int i = 1; i <= n; i++) {
    while (ma.size() > 1 && a[ma.top()] < a[i]) {
      int t = ma.top();
      long long v = a[t];
      ma.pop();
      sum -= v * (t - ma.top());
    }
    sum += a[i] * (i - ma.top());
    ma.push(i);
    ans += sum;
  }
  // min
  sum = 0;
  for (int i = 1; i <= n; i++) {
    while (mi.size() > 1 && a[mi.top()] > a[i]) {
      int t = mi.top();
      long long v = a[t];
      mi.pop();
      sum -= v * (t - mi.top());
    }
    sum += a[i] * (i - mi.top());
    mi.push(i);
    ans -= sum;
  }
  cout << ans << '\n';
  return 0;
}