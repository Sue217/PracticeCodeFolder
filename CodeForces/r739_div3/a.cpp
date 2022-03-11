/**
 *    author: subobo
 *    created: 11.03.2022 14:00:00
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
  vector<int> a;
  for (int i = 1; i <= 2000; i++) {
    if (i % 3 == 0) {
      continue;
    }
    if (i % 10 == 3 || i == 3) {
      continue;
    }
    a.push_back(i);
  }
  while (tt--) {
    int k;
    cin >> k;
    --k;
    cout << a[k] << '\n';
  }
  return 0;
}