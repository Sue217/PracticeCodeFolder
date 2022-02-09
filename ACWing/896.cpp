/**
 *    author: subobo
 *    created: 09.02.2022 13:51:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), seq(n + 1, 0);
  for (int& in : a) {
    cin >> in;
  }
  int len = 0;
  seq.front() = -(int) 2e9;
  for (int i = 0; i < n; i++) {
    int right = lower_bound(seq.begin(), seq.begin() + len + 1, a[i]) - seq.begin() - 1;
    len = max(len, right + 1);
    seq[right + 1] = a[i];
  }
  cout << len << '\n';
  return 0;
}