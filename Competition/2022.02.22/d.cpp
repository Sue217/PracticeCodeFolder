#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bitset<1001> w;
  w[0] = 1;
  // cerr << w[0] << '\n';
  array<int, 7> d{0, 1, 2, 3, 5, 10, 20};
  for (int i = 1; i <= 6; i++) {
    int p;
    cin >> p;
    for (int j = 0; j < p; j++) {
      w |= w << d[i];
    }
  }
  cout << "Total=" << (int) w.count() - 1 << '\n';
  return 0;
}