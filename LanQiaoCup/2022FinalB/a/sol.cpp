/**
 *    author: subobo
 *    created: 18.06.2022 09:04:01
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0;
  for (int a = 1; a <= 4; a++) {
    for (int b = a + 1; b <= 8; b++) {
      for (int c = b + 1; c <= 16; c++) {
        for (int d = c + 1; d <= 32; d++) {
          for (int e = d + 1; e <= 64; e++) {
            for (int f = e + 1; f <= 127; f++) {
              for (int g = f + 1; g <= 253; g++) {
                for (int h = g + 1; h <= 506; h++) {
                  for (int i = h + 1; i <= 1011; i++) {
                    for (int j = i + 1; j <= 2022; j++) {
                      if (a + b + c + d + e + f + g + h + i + j > 2022) break;
                      if (a != b && a != c && a != d && a != e && a != f &&
                          a != g && a != h && a != i && a != j && b != c &&
                          b != d && b != e && b != f && b != g && b != h &&
                          b != i && b != j && c != d && c != e && c != f &&
                          c != g && c != h && c != i && c != j && d != e &&
                          d != f && d != g && d != h && d != i && d != j &&
                          e != f && e != g && e != h && e != i && e != j &&
                          f != g && f != h && f != i && f != j && g != h &&
                          g != i && g != j && h != i && h != j && i != j &&
                          a + b + c + d + e + f + g + h + i + j == 2022) {
                        // cerr << a << b << c << d << e << f << g << h << i << j << '\n';
                        ans += 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}