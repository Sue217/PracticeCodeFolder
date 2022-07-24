/**
 *    author: subobo
 *    created: 24.07.2022 18:13:14
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vector<int> factor(int n) {
  vector<int> a;
  for (int c = 1; c <= n / c; c++) {
    if (n % c == 0) {
      a.push_back(c);
      a.push_back(n / c);
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto a = factor(n);
    for (int i = 0; i < (int) a.size(); i++) {
      cout << a[i] << " \n"[i == (int) a.size() - 1];
    }
  }
  return 0;
}