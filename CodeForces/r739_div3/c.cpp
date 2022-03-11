/**
 *    author: subobo
 *    created: 11.03.2022 14:28:33
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

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
    long long k;
    cin >> k;
    long long x = 1;
    while (x * x < k) {
      ++x;
    }
    // debug(x);
    for (long long y = 1; y <= x; y++) {
      if (x * x - y + 1 == k) {
        cout << x << " " << y << '\n';
        break;
      }
    }
    for (long long a = 1; a <= x; a++) {
      if (x * x - x + 1 - a == k) {
        cout << x - a << " " << x << '\n';
        break;
      }
    }
  }
  return 0;
}