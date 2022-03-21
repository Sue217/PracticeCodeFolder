/**
 *    author: subobo
 *    created: 08.02.2022 14:22:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> match(n);
  int sum = 0;
  for (int& in : match) {
    cin >> in;
    sum += in;
  }
  assert(!(sum % n));
  int avg = sum / n, ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (match[i] != avg) {
      match[i + 1] += match[i] - avg;
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}