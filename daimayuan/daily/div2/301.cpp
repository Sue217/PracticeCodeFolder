/**
 *    author: subobo
 *    created: 12.03.2022 10:18:18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<int> s;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    s.push(i);
    cout << "push " << i << '\n';
    while (!s.empty() && s.top() == a[p]) {
      s.pop();
      cout << "pop" << '\n';
      ++p;
    }
  }
  for (int i = 0; i < (int) s.size(); i++) {
    cout << "pop" << '\n';
  }
  return 0;
}