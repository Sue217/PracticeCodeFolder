/**
 *    author: subobo
 *    created: 30.03.2022 23:23:12
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
  int a, b;
  cin >> a >> b;
  const int N = 10000001;
  bitset<N> used;
  vector<int> p;
  for (int d = 2; d <= N; d++) {
    if (!used[d]) {
      p.push_back(d);
    }
    for (int cc = 0; p[cc] <= N / d; cc++) {
      used[p[cc] * d] = 1;
      if (d % p[cc] == 0) {
        break;
      }
    }
  }
  for (int it : p) {
    if (it >= a && it <= b) {
      string s = to_string(it);
      string res(s);
      reverse(s.begin(), s.end());
      if (s == res) {
        cout << s << '\n';
      }
    }
  }
  return 0;
}