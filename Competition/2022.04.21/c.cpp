#include <bits/stdc++.h>

using namespace std;

int main() {
  double x, y;
  int z;
  cin >> x >> z >> y;
  double r = (z == 0 ? 2.455 : 1.26);
  double res = x * r;
  double eps = 1e-6;
  cout << fixed << setpresicion(2) << res << " ";
  if (res - y < eps) {
    cout << "^_^" << '\n';
  } else {
    cout << "T_T" << '\n';
  }
  return 0;
}