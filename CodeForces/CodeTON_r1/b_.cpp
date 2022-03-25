/**
 *    author: subobo
 *    created: 25.03.2022 22:30:57
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
    }
    bool ok = true;
    for (int it : st) {
      if (st.find(it + k) != st.end()) {
        ok = false;
        break;
      }
    }
    cout << (!ok ? "YES" : "NO") << '\n';
  }
  return 0;
}