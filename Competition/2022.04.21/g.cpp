#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  int kk = 1;
  vector<int> cc(n);
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    if (j % 2 == 0) {
      if (kk == k + 1) {
        kk = 1;
      }
      cc[i] = kk;
      ++kk;
    }
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (i >= cc[j]) {
        sum += g[i - cc[j]][j];
      } else {
        sum += x;
      }
    }
    cout << sum << " \n"[i == n - 1];
  }
  return 0;
}