/**
 *    author: subobo
 *    created: 09.01.2022 10:22:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (auto& in : seq) {
      cin >> in;
    }
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
      left[i] = 1;
      for (int j = 0; j < i; j++) {
        if (seq[i] < seq[j]) {
          left[i] = max(left[i], left[j] + 1);
        }
      }
    }
    for (int i = n - 1; ~i; i--) {
      right[i] = 1;
      for (int j = n - 1; j > i; j--) {
        if (seq[i] < seq[j]) {
          right[i] = max(right[i], right[j] + 1);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, left[i]);
      res = max(res, right[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
