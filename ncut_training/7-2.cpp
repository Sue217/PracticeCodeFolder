/**
 *    author: subobo
 *    created: 16.01.2022 11:18:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  constexpr int maxn = 10000;
  vector<bool> is(maxn);
  vector<int> prime;
  for (int i = 2; i <= maxn; i++) {
    if (!is[i]) {
      prime.emplace_back(i);
      for (int j = i; j <= maxn; j += i) {
        is[j] = true;
      }
    }
  }
  // for (auto it : prime) { cerr << it << " "; }
  int n, m;
  while (cin >> n >> m) {
    int L = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
    int R = upper_bound(prime.begin(), prime.end(), m) - prime.begin() - 1;
    for (int i = L; i < R; i++) {
      cout << prime[i] << " ";
    }
    cout << prime[R] << '\n';
  }
  return 0;
}
