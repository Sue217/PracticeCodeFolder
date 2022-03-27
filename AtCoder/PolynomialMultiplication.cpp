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
  for (int i = 0; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      c[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i <= n + m; i++) {
    cout << c[i] << " \n"[i == n + m];
  }
  return 0;
}

/* sample input 1
n = 1, m = 2
a: [1 2]
c: [2 4 6]
result:
b: [2 8 14 12]
*/

/* sample input 2
n = 3, m = 2
a: [4 5 17 2]
c: [1 2 1]
result:
b: [4 13 31 41 21 2]
*/