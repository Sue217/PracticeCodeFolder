/**
 *    author: subobo
 *    created: 30.01.2022 14:53:39
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T& v) {
  v = 0;
  __int128 s = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      s = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = v * 10 + c - '0';
    c = getchar();
  }
}

template<typename T, typename... A>
inline void read(T& v, A&... args) {
  read(v);
  read(args...);
}

inline void print(__int128 v) {
  if (v < 0) {
    putchar('-');
    v = -v;
  }
  if (v > 9) {
    print(v / 10);
  }
  putchar(v % 10 + '0');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  __int128 a, b, p;
  read(a, b, p);
  print(a * b % p);
  return 0;
}