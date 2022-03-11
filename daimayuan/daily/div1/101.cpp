/**
 *    author: subobo
 *    created: 24.02.2022 20:32:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& in : a) {
    cin >> in;
  }
  if (n == 1) {
    cout << (long long) a.back() + k << '\n';
    return 0;
  }
  sort(a.begin(), a.end());
  auto check = [&](long long x) {
    long long remain = k;
    for (int it : a) {
      if (remain >= (x - it)) {
        if (x - it > 0) {
          remain -= (x - it);
        }
      } else {
        return false;
      }
    }
    return true;
  };
  long long left = 0, right = k;
  while (right - left > 1) {
    long long mid = (left + right + 1) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  // cerr << left << " " << right << '\n';
  cout << left << '\n';
  return 0;
}