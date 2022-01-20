/**
 *    author: subobo
 *    created: 20.01.2022 15:30:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (auto& in : seq) {
    cin >> in;
  }
  sort(seq.begin(), seq.end());
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int ql, qr;
    cin >> ql >> qr;
    int L = lower_bound(seq.begin(), seq.end(), ql) - seq.begin();
    int R = upper_bound(seq.begin(), seq.end(), qr) - seq.begin() - 1;
    cout << R - L + 1 << " ";
  }
  cout << '\n';
  return 0;
}