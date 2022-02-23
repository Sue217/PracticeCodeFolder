/**
 *    author: subobo
 *    created: 23.02.2022 08:43:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 6> a{1, 2, 3, 5, 10, 20};
  bitset<1001> can;
  can[0] = 1;
  for (int i = 0; i < 6; i++) {
    int has;
    cin >> has;
    for (int j = 0; j < has; j++) {
      can |= (can << a[i]);
    }
  }
  cout << "Total=" << can.count() - 1 << '\n';
  return 0;
}
