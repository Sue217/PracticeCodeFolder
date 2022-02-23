/**
 *    author: subobo
 *    created: 23.02.2022 09:17:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  bitset<1024> can;
  can[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    can |= (can << x);
  }
  // get result does have can[m] O(nm/32)
  puts(can[m] ? "Yes" : "No");
  // count the number of existing elements O(1)
  cout << can.count() - 1 << '\n';
  return 0;
}