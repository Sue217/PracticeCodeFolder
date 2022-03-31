/**
 *    author: subobo
 *    created: 31.03.2022 23:26:09
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
    string s;
    cin >> s;
    int n = (int) s.size();
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (st.empty()) {
        st.push(s[i]);
        continue;
      }
      while (!st.empty() && st.top() != s[i]) {
        ans += 1;
        st.pop();
      }
      if (!st.empty()) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    ans += (int) st.size();
    cout << ans << '\n';
  }
  return 0;
}