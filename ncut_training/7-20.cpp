/**
 *    author: subobo
 *    created: 28.01.2022 22:17:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int& in : seq) {
    cin >> in;
  }
  int l, r;
  cin >> l >> r;
  int tag = 998244353;
  for (int& it : seq) {
    if (it >= l && it <= r) {
      it = tag;
    }
  }
  int ed = n;
  for (int i = n - 1; i >= 0; i--) {
    if (seq[i] != tag) {
      ed = i;
      break;
    }
  }
  if (ed != n) {
    for (int i = 0; i < ed; i++) {
      if (seq[i] != tag) {
        cout << seq[i] << " ";
      }
    }
    cout << seq[ed] << '\n';
  }
  return 0;
}