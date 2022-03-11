/**
 *    author: subobo
 *    created: 03.03.2022 21:48:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& in : a) {
    cin >> in;
  }
  map<int, int> cnt;
  vector<long long> sum(1);
  for (int i = 0; i < n; i++) {
    int t = (sum.back() + a[i]) % n;
    if (t == 0) {
      cout << i + 1 << '\n';
      for (int id = 1; id <= i + 1; id++) {
        cout << id << " \n"[id == i + 1];
      }
      return 0;
    }
    // a [a, b, c] n = 3
    // s [a%3, (a+b)%3, (a+b+c)%3]
    // make a≠0 && a+b≠0 && a+b+c≠0 && a%3 == (a+b+c)%3
    // have a+k*n = a+b+c
    // thus b+c = k*n =0(mod n)
    if (cnt.count(t) != 0) {
      int l = cnt[t] + 2, r = i + 1;
      cout << r - l + 1 << '\n';
      for (int id = l; id <= r; id++) {
        cout << id << " \n"[id == r];
      }
      return 0;
    }
    sum.push_back(t);
    cnt[t] = i;
  }
  cout << -1 << '\n';
  return 0;
}
