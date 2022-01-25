/**
 *    author: subobo
 *    created: 23.01.2022 19:22:34
**/
#include <iostream>
#pragma GCC optimize(2)

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  // cin >> n;
  n = read<int>();
  int a, b, c, d, e;
  a = b = c = d = e = 0;
  for (int i = 0; i < n; i++) {
    int x;
    x = read<int>();
    if (x >= 90) {
      ++a;
    } else
    if (x >= 80) {
      ++b;
    } else
    if (x >= 70) {
      ++c;
    } else
    if (x >= 60) {
      ++d;
    } else {
      ++e;
    }
  }
  cout << a << " " << b << " " << c << " " << d << " " << e;
  return 0;
}