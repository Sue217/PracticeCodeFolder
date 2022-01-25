/**
 *    author: subobo
 *    created: 25.01.2022 21:32:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int times = 0, sum = 0;
  for (int i = 0; i < m + 1; i++) {
    int d;
    cin >> d;
    if (d > n) {
      cout << "No Solution!" << '\n';
      return 0;
    }
    sum += d;
    if (sum > n) {
      times += 1;
      sum = d;
    }
  }
  cout << times << '\n';
  return 0;
}