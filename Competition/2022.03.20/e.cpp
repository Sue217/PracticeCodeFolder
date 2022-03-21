/**
 *    author: subobo
 *    created: 20.03.2022 18:09:10
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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x] += 1;
  }
  for (auto p : m) {
    cout << p.first << ":" << p.second << '\n';
  }
  return 0;
}