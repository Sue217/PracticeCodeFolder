/**
 *    author: subobo
 *    created: 23.01.2022 19:51:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Sum = [&](int x) {
    vector<long long> sum(x);
    iota(sum.begin(), sum.end(), 1);
    return accumulate(sum.begin(), sum.end(), decltype(sum)::value_type(0));
  };
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += Sum(i);
  }
  cout << "sum = " << ans << '\n';
  return 0;
}