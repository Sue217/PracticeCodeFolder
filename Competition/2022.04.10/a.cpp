/**
 *    author: subobo
 *    created: 10.04.2022 14:41:08
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
  cin.get();
  string s;
  getline(cin, s);
  int m = (int) s.size();
  int e = m % n;
  for (int i = 0; i < n; i++) {
    int d = i;
    string xs("");
    while (d < m) {
      xs += s[d];
      d += n;
    }
    if (i > e - 1 && e != 0) {
      xs += " ";
    }
    reverse(xs.begin(), xs.end());
    cout << xs << '\n';
  } 
  return 0;
}