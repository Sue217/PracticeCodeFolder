/**
 *    author: subobo
 *    created: 25.01.2022 20:02:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] += 1;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[x] += 1;
  }
  long long ans = 0;
  for (auto i : a) {
    long long sum = 0;
    for (auto j : b) {
      int p = i.first + j.first;
      if (b.find(p) != b.end()) {
        sum += 1ll * p * i.second * j.second * b[p];
      }
    }
    ans += sum;
  }
  cout << ans << '\n';
  return 0;
}