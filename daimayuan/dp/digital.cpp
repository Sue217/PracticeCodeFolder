/**
 *    author: subobo
 *    created: 06.03.2022 15:25:33
**/
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 17;
vector<long long> ten(N), dp(N);

inline vector<long long> calc(long long x) {
  vector<long long> dig(10);
  vector<int> a(1);
  long long t = x;
  while (x) {
    a.push_back(x % 10ll);
    x /= 10ll;
  }
  int n = (int) a.size();
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < 10; j++) {
      dig[j] += dp[i - 1] * a[i];
    }
    for (int j = 0; j < a[i]; j++) {
      dig[j] += ten[i - 1];
    }
    t -= a[i] * ten[i - 1];
    dig[a[i]] += t + 1;
    dig[0] -= ten[i - 1];
  }
  return dig;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long L, R;
  cin >> L >> R;
  ten[0] = 1ll;
  for (int i = 1; i < N; i++) {
    dp[i] = 10ll * dp[i - 1] + ten[i - 1];
    ten[i] = ten[i - 1] * 10ll;
  }
  vector<long long> DL = calc(L - 1), DR = calc(R);
  for (int it = 0; it < 10; it++) {
    cout << DR[it] - DL[it] << " \n"[it == 9];
  }
  return 0;
}