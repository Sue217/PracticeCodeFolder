#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 1000;
  int M = 10000;
  int tt = 100000;
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  cout << tt << '\n';
  while (tt--) {
    cout << rng() % N << " ";
    int a = rng() % M;
    int b = rng() % M;
    while (a > b) {
      a = rng() % M;
      b = rng() % M;
    }
    if (a <= b) cout << a << " " << b << '\n';
  }
  return 0;
}