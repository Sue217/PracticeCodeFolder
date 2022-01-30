/**
 *    author: subobo
 *    created: 30.01.2022 20:21:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  deque<int> dq;
  dq.push_back(0);
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'R') {
      cout << dq.front() << " ";
      dq.pop_front();
      dq.push_front(i + 1);
    } else {
      dq.push_front(i + 1);
    }
  }
  while (!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << '\n';
  return 0;
}