/**
 *    author: subobo
 *    created: 08.02.2022 15:14:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& in : a) {
    cin >> in;
  }
  int days = a.front();
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] > 0) {
      days += (a[i] - a[i - 1]);
    }
  }
  cout << days << '\n';
  return 0;
}