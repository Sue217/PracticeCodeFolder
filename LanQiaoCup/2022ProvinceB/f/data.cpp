#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int out = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << out << " \n"[j == m - 1];
      ++out;
    }
  }
  return 0;
}