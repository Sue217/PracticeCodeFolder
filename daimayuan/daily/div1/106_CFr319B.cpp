/**
 *    author: subobo
 *    created: 03.03.2022 23:03:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (m <= n) {
    puts("YES");
    return 0;
  }
  vector<int> cnt;
  set<int> has;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a %= m;
    for (int j = 0, s = (int) cnt.size(); j < s; j++) {
      int t = (cnt[j] + a) % m;
      if (has.find(t) == has.end()) {
        has.insert(t);
        cnt.push_back(t);
      }
    }
    if (has.find(a) == has.end()) {
      has.insert(a);
      cnt.push_back(a);
    }
  }
  for (int it : cnt) {
    if (it == 0) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}