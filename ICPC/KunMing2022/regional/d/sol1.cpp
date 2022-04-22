#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  if (k == 0) {
    cout << 9 << '\n';
    cout << "7 8 9 4 5 6 1 2 3" << '\n';
    return 0;
  }
  if (k == 1) {
    cout << 6 << '\n';
    cout << "1 1 4 5 1 4" << '\n';
    return 0;
  }
  --k;
  vector<int> a;
  int v = 1;
  while (k > 0) {
    int x = 1;
    while ((1 << x) - 1 <= k) {
      ++x;
    }
    --x;
    k -= (1 << x) - 1;
    cerr << k << '\n';
    while (x--) {
      a.push_back(v);
    }
    ++v;
  }
  cout << a.size() << '\n';
  for (int i = 0; i < (int) a.size(); i++) {
    cout << a[i] << " \n"[i == (int) a.size() - 1];
  }
  return 0;
}