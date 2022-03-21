/**
 *    author: subobo
 *    created: 20.02.2022 16:10:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> hill(n, 0);
  for (int& in : hill) {
    cin >> in;
  }
  long long ans = (long long) 2e18;
  for (int l = 1; l <= 83; l++) {
    int r = l + 17;
    long long tot = 0;
    for (int it : hill) {
      if (it < l) {
        tot += (l - it) * (l - it);
      } else
      if (it > r) {
        tot += (it - r) * (it - r);
      }
    }
    ans = min(ans, tot);
  }
  cout << ans << '\n';
  return 0;
}