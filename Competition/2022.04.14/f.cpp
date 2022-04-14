/**
 *    author: subobo
 *    created: 14.04.2022 17:50:27
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

inline __int128 read() {
  __int128 x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

inline void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}
/*
bool cmp(__int128 x, __int128 y) {
  return x > y;
}
*/

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    unsigned long long n, k;
    cin >> n >> k;
    __int128 sum = n * (n + 1) / 2;
    __int128 kk = (__int128) pow(2, k);
    if (n < kk || kk == 1) {
      print(sum);
      puts("");
      continue;
    }
    if (n == 1 || n == 2) {
      cout << n << '\n';
      continue;
    }
    __int128 ans = 0;
    if (n % 2 == 1) {
      int bit = (n - kk + 1) * 0.5;
      ans = (kk + 1 + n) * bit * 0.5;
      ans += (2 + bit) * (bit - 1) * 0.5;
    } else {
      int bit = (n - kk) * 0.5;
      ans = (kk + n) * bit * 0.5;
      ++bit;
      ans += (1 + bit) * bit * 0.5;
    }
    int bit = (kk - 2) * 0.5;
    ans += (2 + kk) * bit * 0.5;
    ans += (__int128) pow(4, k) / 3;
    ans -= kk;
    print(ans);
    puts("");
  }
  return 0;
}