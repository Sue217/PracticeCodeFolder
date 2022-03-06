/**
 *    author: subobo
 *    created: 05.03.2022 16:21:36
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> a(22);
vector<long long> dig(10), ten(17);

inline void calc(long long x, int sign) {
  vector<int> a;
  while (x) {
    a.push_back(x % 10ll);
    x /= 10ll;
  }
  a.push_back(0);
  reverse(a.begin(), a.end());
  int m = (int) a.size();
  for (int i = 1; i <= m; i++) {
    // j[1,...,i-1]: a[i]*10^(m-i)
    for (int j = 1; j < i; j++) {
      dig[a[j]] += sign * a[i] * ten[m - i];
    }
    // j[i]: 10^(m-i)
    for (int j = 1; j < a[i]; j++) {
      dig[j] += sign * ten[m - i];
    }
    if (i != 1 && a[i] != 0) {
      dig[0] += sign * ten[m - i];
    }
    // j[i+1,...,m]: a[i]*10^(m-i-1)*(m-i)
    if (i != m) {
      for (int j = 1; j < 10; j++) {
        dig[j] += sign * a[i] * ten[m - i - 1] * (m - i);
      }
      if (i != 1) {
        dig[0] += sign * a[i] * ten[m - i - 1] * (m - i);
      }
    }
    if (i == 1) {
      if (m >= 2) {
        dig[0] += sign * (a[1] - 1) * ten[m - 2] * (m - 1);
      }
      for (int j = 2; j < m; j++) {
        dig[0] += sign * 9 * ten[m - j - 1] * (m - j);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    dig[a[i]] += sign;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long L, R;
  cin >> L >> R;
  ten[0] = 1;
  for (int i = 1; i <= 16; i++) {
    ten[i] = ten[i - 1] * 10ll;
  }
  calc(R, 1);
  calc(L - 1, -1);
  for (int it = 0; it < 10; it++) {
    cout << dig[it] << " \n"[it == 9];
  }
  return 0;
}