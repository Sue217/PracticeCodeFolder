/**
 *    author: subobo
 *    created: 16.04.2022 13:42:50
**/
#include <bits/stdc++.h>

using namespace std;

unsigned int A,B,C;
inline unsigned int rng61() {
  A ^= A << 16;
  A ^= A >> 5;
  A ^= A << 1;
  unsigned int t = A;
  A = B;
  B = C;
  C ^= t ^ A;
  return C;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> A >> B >> C;
  vector<long long> f(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    f[i] = (long long) rng61();
  }
  vector<long long> g(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    int j = i;
    while (true) {
      g[i] += f[j];
      if (j == 0) break;
      j = (j - 1) & i;
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    ans ^= g[i];
  }
  cout << ans << '\n';
  cerr << "time: " << clock() / 1000 << " ms" << '\n';
}