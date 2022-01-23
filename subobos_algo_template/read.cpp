/**
 *    author: Jingbo Su
 *    created: 23.01.2022
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline T read () {
  T v = 0, s = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      s = -1;
      c = getchar();
    }
  }
  while (c >= '0' && c <= '9') {
    v = v * 10 + c - '0';
    c = getchar();
  }
  return v * s;
}
