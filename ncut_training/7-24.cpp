/**
 *    author: subobo
 *    created: 01.02.2022 18:27:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> match(n);
  int sum = 0;
  for (int& in : match) {
    cin >> in;
    sum += in;
  }
  assert(!(sum % n));
  int plus = 0, minus = 0, avg = sum / n;
  for (int m : match) {
    if (m < avg) {
      minus += 1;
    } else
    if (m > avg) {
      plus += 1;
    }
  }
  cout << max(plus, minus) << '\n';
  return 0;
}