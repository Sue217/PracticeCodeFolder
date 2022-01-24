/**
 *    author: subobo
 *    created: 23.01.2022 19:22:34
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  // n = read<int>();
  cin >> n;
  auto check = [&](int x) {
    if (x >= 90) {
      return 0;
    } else
    if (x >= 80) {
      return 1;
    } else
    if (x >= 70) {
      return 2;
    } else
    if (x >= 60) {
      return 3;
    } else {
      return 4;
    }
  };
  map<int, int> level;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    level[check(x)] += 1;
  }
  for (int id = 0; id < 4; id++) {
    cout << level[id] << " ";
  }
  cout << level[4];
  return 0;
}