/**
 *    author: Jingbo Su
 *    created: 16.03.2022
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>
inline T pow(const T& a, const T& b, const U& mod) {
  assert(b >= 0);
  T x = a, p = b, ans = 1;
  while (p > 0) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans % mod;
}

int main() {
  long long a, b, p;
  cin >> a >> b >> p;
  cout << pow(a, b, p) << '\n';
  return 0;
}