#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << max(i - 1, n - i) * 2 << '\n';
  }
  return 0;
}