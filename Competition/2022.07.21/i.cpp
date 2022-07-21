/**
 *    author: subobo
 *    created: 21.07.2022 16:16:07
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// Recursive function to return gcd of a and b
int ___gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return ___gcd(b, a % b);
}

// Function to return LCM of two numbers
int ___lcm(int a, int b) { return (a / ___gcd(a, b)) * b; }

bool isprime(const int& n) {
  for (int c = 2; c <= n / c; c++) {
    if (n % c == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int p, q, ed;
    cin >> p >> q >> ed;
    int m = ___lcm(p, q) + 1;
    if (!isprime(m)) m -= 2;
    if (!isprime(m)) {
      cout << "shuanQ" << '\n';
      continue;
    }
    int r = ed * q % m;
    if (ed == r * p % m) {
      cout << r << '\n';
      continue;
    }
    cout << "shuanQ" << '\n';
  }
  return 0;
}