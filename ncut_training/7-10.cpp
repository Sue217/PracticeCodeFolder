/**
 *    author: subobo
 *    created: 25.01.2022 18:18:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
    }
    if (st.size() == 1) {
      cout << "NO" << '\n';
    } else {
      auto it = st.begin();
      it++;
      cout << *it << '\n';
    }
  }
  return 0;
}