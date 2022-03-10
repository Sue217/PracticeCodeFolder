/**
 *    author: subobo
 *    created: 09.03.2022 11:08:37
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      int ptr = find(a.begin(), a.end(), i + 1) - a.begin() + 1;
      b[i] = ptr % (i + 1);
      // if (ptr == i + 1) {
      //   b[i] = 0;
      // } else {
      //   b[i] = ptr;
      // }
      rotate(a.begin(), a.begin() + ptr, a.begin() + i + 1);
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}