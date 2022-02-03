/**
 *    author: subobo
 *    created: 03.02.2022 14:25:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(9);
  for (int i = 0; i < 9; i++) {
    a[i] = i + 1;
  }
  auto calc = [&](int x, int y) {
    int ans = 0;
    for (int i = x; i <= y; i++) {
      ans = ans * 10 + a[i];
    }
    return ans;
  };
  int ans = 0;
  do {
    for (int i = 0; i < 9; i++) {
      for (int j = i + 1; j < 9; j++) {
        int a = calc(0, i);
        int b = calc(i + 1, j);
        int c = calc(j + 1, 8);
        if (b == c * (n - a)) {
          ans += 1;
        }
      }
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << '\n';
  return 0;
}