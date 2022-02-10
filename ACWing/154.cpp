/**
 *    author: subobo
 *    created: 10.02.2022 15:38:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& in : a) {
    cin >> in;
  }
  deque<int> mono;
  for (int it = 0; it < n; it++) {
    if (!mono.empty() && mono.front() <= it - k) {
      mono.pop_front();
    }
    while (!mono.empty() && a[mono.back()] >= a[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it - k + 1 >= 0) {
      cout << a[mono.front()] << " \n"[it == n - 1];
    }
  }
  mono.clear();
  for (int it = 0; it < n; it++) {
    if (!mono.empty() && mono.front() <= it - k) {
      mono.pop_front();
    }
    while (!mono.empty() && a[mono.back()] <= a[it]) {
      mono.pop_back();
    }
    mono.push_back(it);
    if (it - k + 1 >= 0) {
      cout << a[mono.front()] << " \n"[it == n - 1];
    }
  }
  return 0;
}