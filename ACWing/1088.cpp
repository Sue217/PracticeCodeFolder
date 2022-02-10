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
  vector<long long> sum(n * 2 + 4, 0);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i + n] = p[i] - d[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    sum[i] += sum[i - 1];
  }
  deque<int> mono;
  vector<bool> yes(n + 1);
  for (int it = n * 2; it >= 1; it--) {
    if (!mono.empty() && mono.front() > it + n - 1) {
      mono.pop_front();
    }
    while (!mono.empty() && sum[mono.back()] >= sum[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it <= n && sum[mono.front()] - sum[it - 1] >= 0) {
      yes[it] = true;
    }
  }
  // anticlockwise
  d[0] = d[n];
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i + n] = p[i] - d[i - 1];
  }
  for (int i = n * 2; i >= 1; i--) {
    sum[i] += sum[i + 1];
  }
  mono.clear();
  for (int it = 1; it <= n * 2; it++) {
    if (!mono.empty() && mono.front() < it - n + 1) {
      mono.pop_front();
    }
    while (!mono.empty() && sum[mono.back()] >= sum[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it >= n + 1 && sum[mono.front()] - sum[it + 1] >= 0) {
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