/**
 *    author: subobo
 *    created: 29.01.2022 15:30:37
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
    vector<int> piles(n);
    for (int& in : piles) {
      cin >> in;
    }
    int ma = *max_element(piles.begin(), piles.end());
    int sum = accumulate(piles.begin(), piles.end(), 0);
    if (ma * 2 > sum || sum % 2 != 0) {
      puts("T");
    } else {
      puts("HL");
    }
  }
  return 0;
}