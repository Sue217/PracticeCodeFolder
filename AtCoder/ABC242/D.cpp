/**
 *    author: subobo
 *    created: 06.03.2022 11:53:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int q;
  cin >> s >> q;
  function<int(long long, long long)> get = [&](long long t, long long k) {
    if (t == 0) {
      return s[k] - 'A';
    } else
    if (k == 0) {
      return (int) ((s[0] - 'A' + t) % 3);
    } else {
      return (int) ((get(t - 1, k / 2) + k % 2 + 1) % 3);
    }
  };
  while (q--) {
    long long t, k;
    cin >> t >> k;
    k -= 1;
    cout << (char) ('A' + get(t, k)) << '\n';
  }
  return 0;
}