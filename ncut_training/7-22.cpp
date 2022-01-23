/**
 *    author: subobo
 *    created: 19.01.2022 09:28:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  queue<int> que;
  for (int i = 0; i < n; i++) {
    int op;
    cin >> op;
    if (op == 0) {
      if (!que.empty()) {
        int t = que.front();
        que.pop();
        cout << t << '\n';
      } else {
        cout << "invalid" << '\n';
      }
    } else {
      int d;
      cin >> d;
      que.push(d);
    }
  }
  return 0;
}