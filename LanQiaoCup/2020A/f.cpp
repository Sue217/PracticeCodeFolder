/**
 *    author: subobo
 *    created: 05.04.2022 00:00:49
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
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << *max_element(a.begin(), a.end()) << '\n';
  cout << *min_element(a.begin(), a.end()) << '\n';
  double sum = accumulate(a.begin(), a.end(), 0) * 1.0 / (double) n;
  cout << fixed << setprecision(2) << sum << '\n';
  return 0;
}