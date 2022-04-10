/**
 *    author: subobo
 *    created: 10.04.2022 15:39:11
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int dd, hh, mm;
    scanf("%d %d:%d", &dd, &hh, &mm);
    if (dd == 0) {
      printf("%d %02d:%02d", dd, hh, mm);
      continue;
    }
    int f = 1 - (dd % 2);
    dd = dd / 2 + dd % 2;
    if (hh % 2 == 0) {
      mm /= 2;
    } else {
      mm = (mm + 60) / 2;
    }
    hh /= 2;
    if (f == 1) {
      hh += 12;
    }
    printf("%d %02d:%02d\n", dd, hh, mm);
  }
  return 0;
}