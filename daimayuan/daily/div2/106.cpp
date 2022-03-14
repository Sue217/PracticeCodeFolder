/**
 *    author: subobo
 *    created: 14.03.2022 10:54:44
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
  set<pair<int, int>> sp;
  sp.insert(make_pair((int) 2e9, 1));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto ptr = lower_bound(sp.begin(), sp.end(), make_pair(x, 0));
    auto add = [&](int x, int y) {
      if (x <= y) {
        sp.insert(make_pair(y, x));
      }
    };
    if (ptr->second <= x) {
      cout << x << " ";
      add(ptr->second, x - 1);
      add(x + 1, ptr->first);
    } else {
      cout << ptr->second << " ";
      add(ptr->second + 1, ptr->first);
    }
    sp.erase(*ptr);
  }
  return 0;
}