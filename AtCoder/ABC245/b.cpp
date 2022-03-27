/**
 *    author: subobo
 *    created: 27.03.2022 13:19:09
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
  set<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  for (int i = 0; i <= 2000; i++) {
    if (st.find(i) == st.end()) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}