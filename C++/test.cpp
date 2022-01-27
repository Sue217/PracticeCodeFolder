/**
 *    author: subobo
 *    created: 27.01.2022 14:44:14
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read (T& v) {
  v = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 1) + (v << 3) + (c ^ 48);
    c = getchar();
  }
}

template<typename T, typename... A>
inline void read(T& v, A&... args) {
  read(v);
  read(args...);
}

int main() {
  int n, m, u, v, w;
  read(n, m, u, v, w);
  cerr << n << " " << m << " " << u << " " << v << " " << w << '\n';
}