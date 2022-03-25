/**
 *    author: subobo
 *    created: 24.03.2022 22:35:45
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
  while (tt--) {
    int n;
    cin >> n;
    map<long long, int> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]] = i;
    }
    sort(a.begin(), a.end());
    cout << m[a.front()] + 1 << " " << m[a.back()] + 1 << '\n';
  }
  return 0;
}