/**
 *    author: Jingbo Su
 *    created: 23.01.2022
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline T read () {
  T v = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 1) + (v << 3) + (c ^ 48);
    c = getchar();
  }
  return v;
}
