/**
 *    author: subobo
 *    created: 27.03.2022
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1), c(n + m + 1);
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n + m; i++) {
    cin >> c[i];
  }
  reverse(a.begin(), a.end());
  reverse(c.begin(), c.end());
  for (int i = m; i >= 0; i--) {
    b[i] = c[i + n] / a[n];
    for (int j = n; j >= 0; j--) {
      c[i + j] -= b[i] * a[j];
    }
  }
  for (int i = m; i >= 0; i--) {
    cout << b[i] << " \n"[i == 0];
  }
  return 0;
}

/* sample input 1
n = 1, m = 2
a: [1 2]
c: [2 8 14 12]
result:
b: [2 4 6]
*/

/* sample input 2
n = 3, m = 2
a: [4 5 17 2]
c: [4 13 31 41 21 2]
result:
b: [1 2 1]
*/