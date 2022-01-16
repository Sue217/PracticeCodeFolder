/**
 *    author: subobo
 *    created: 16.01.2022 11:33:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> seq(n);
  for (auto& in : seq) {
    cin >> in;
  }
  for (int i = 1; i < m; i++) {
    int query;
    cin >> query;
    cout << lower_bound(seq.begin(), seq.end(), query) - seq.begin() << " ";
  }
  int query;
  cin >> query;
  cout << lower_bound(seq.begin(), seq.end(), query) - seq.begin();
  return 0;
}
