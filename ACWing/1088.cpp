/**
 *    author: subobo
 *    created: 10.02.2022 17:17:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> d[i];
  }
  // clockwise
  vector<int> cwsum(n * 2 + 4, 0), atsum(n * 2 + 4, 0);
  for (int i = 1; i <= n; i++) {
    cwsum[i] = cwsum[i + n] = p[i] - d[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    cwsum[i] += cwsum[i - 1];
  }
  deque<int> mono;
  vector<bool> yes(n * 2 + 1);
  for (int it = n * 2; it >= 1; it--) {
    if (!mono.empty() && mono.front() > it + n - 1) {
      mono.pop_front();
    }
    while (!mono.empty() && cwsum[mono.back()] >= cwsum[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it <= n && cwsum[mono.front()] - cwsum[it - 1] >= 0) {
      yes[it] = true;
    }
  }
  // anticlockwise
  mono.clear();
  d[0] = d[n];
  for (int i = n; i >= 1; i--) {
    atsum[i] = atsum[i + n] = p[i] - d[i - 1];
  }
  for (int i = n * 2; i >= 1; i--) {
    atsum[i] += atsum[i + 1];
  }
  for (int it = 1; it <= n * 2; it++) {
    if (!mono.empty() && mono.front() < it - n + 1) {
      mono.pop_front();
    }
    while (!mono.empty() && atsum[mono.back()] >= atsum[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it > n && atsum[mono.front()] - atsum[it + 1] >= 0) {
      yes[it - n] = true;
    }
  }
  for (int it = 1; it <= n; it++) {
    if (yes[it]) {
      cout << "TAK" << '\n';
    } else {
      cout << "NIE" << '\n';
    }
  }
  return 0;
}