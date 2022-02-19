/**
 *    author: subobo
 *    created: 19.02.2022 20:27:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long double n;
  cin >> n;
  cout << fixed << setprecision(6) << (long double) sqrt(n) * sqrt(n + 12800000) << '\n';
  return 0;
}