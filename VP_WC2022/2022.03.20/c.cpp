/**
 *    author: subobo
 *    created: 20.03.2022 19:38:52
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
  list<int> lst;
  int n, m;
  cin >> n >> m;
  while (m--) {
    char op;
    if (op == 'l') {
      int x;
      cin >> x;
      --x;
      lst.push_back(x);
    }
    if (op == 'C') {
      int x, y;
      cin >> x >> y;
      --x; --y;
      lst.emplace(lst.begin() + y, x);
    }
    if (op == 'L') {
      int x;
      cin >> x;
      --x;
      lst.erase(lst.begin() + x);
    }
  }
  for (int it : lst) {
    cout << it << " ";
  }
  cout << '\n';
  return 0;
}