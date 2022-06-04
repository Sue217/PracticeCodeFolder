/**
 *    author: subobo
 *    created: 03.06.2022 11:12:57
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
  int n, m;
  cin >> n >> m;
  auto a = new int* [n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i] = new int [j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << " \n"[j == m - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    delete [] a[i];
  }
  delete [] a;
  return 0;
}