/**
 *    author: subobo
 *    created: 06.03.2022 23:09:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& in : a) {
      cin >> in;
    }
    int R = 0, L = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        L = i - 1;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        R = i + 1;
        break;
      }
    }
    cout << R - L << '\n';
  }
  return 0;
}