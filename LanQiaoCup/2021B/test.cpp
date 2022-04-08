#include <bits/stdc++.h>

using namespace std;

int main() {
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < 100000; i++) {
    cout << rng() % 2 << " " << rng() % 100000 << '\n';
  }
  // cerr << "time = " << clock() << " ms" << '\n';
  return 0;
}
