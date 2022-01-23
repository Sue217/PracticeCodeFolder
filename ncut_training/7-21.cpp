/**
 *    author: subobo
 *    created: 19.01.2022 09:25:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> stk;
  for (int i = 0; i < n; i++) {
    int op;
    cin >> op;
    if (op == 0) {
      if (!stk.empty()) {
        int t = stk.top();
        stk.pop();
        cout << t << '\n';
      } else {
        cout << "invalid" << '\n';
      }
    } else {
      int d;
      cin >> d;
      stk.push(d);
    }
  }
  return 0;
}