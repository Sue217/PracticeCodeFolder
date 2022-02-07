/**
 *    author: subobo
 *    created: 06.02.2022 22:50:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for (auto& in : a) {
      cin >> in;
    }
    if (n <= 2) {
      puts("Alice");
    } else {
      puts("Bob");
    }
  }
  return 0;
}