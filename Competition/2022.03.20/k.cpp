/**
 *    author: subobo
 *    created: 20.03.2022 20:33:47
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
  queue<int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      b.push(x);
    } else {
      a.push(x);
    }
  }
  int time = 0;
  while (!a.empty() && !b.empty()) {
    time += 1;
    if (time == 1 && !a.empty()) {
      cout << a.front() << " ";
      a.pop();
    }
    if (time == 2 && !a.empty() && !b.empty()) {
      cout << a.front() << " " << b.front() << " ";
      a.pop(); b.pop();
      time = 0;
    }
  }
  while (a.size() > 1) {
    cout << a.front() << " ";
    a.pop();
  }
  while (b.size() > 1) {
    cout << b.front() << " ";
    b.pop();
  }
  if (a.size() == 1) {
    cout << a.front();
  }
  if (b.size() == 1) {
    cout << b.front();
  }
  return 0;
}