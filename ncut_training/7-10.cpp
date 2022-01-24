/**
 *    author: subobo
 *    created: 24.01.2022 21:10:50
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
    vector<int> seq(n);
    for (auto& in : seq) {
      cin >> in;
    }
    sort(seq.begin(), seq.end());
    int sec = seq.front();
    bool ok = true;
    for (auto it : seq) {
      if (it > sec) {
        cout << it << '\n';
        ok = false;
        break;
      }
    }
    if (ok) {
      puts("NO");
    }
  }
  return 0;
}