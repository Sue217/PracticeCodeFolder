/**
 *    author: subobo
 *    created: 05.02.2022 17:25:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> milk;
  for (int i = 0; i < n; i++) {
    int st, ed;
    cin >> st >> ed;
    milk.emplace_back(st, ed);
  }
  sort(milk.begin(), milk.end());
  int st = milk.front().first, ed = milk.front().second, milking = 0, idle = 0;
  for (auto it : milk) {
    if (it.first <= ed) {
      ed = max(ed, it.second);
    } else {
      idle = max(idle, it.first - ed);
      milking = max(milking, ed - st);
      st = it.first;
      ed = it.second;
    }
  }
  milking = max(milking, ed - st);
  cout << milking << " " << idle << '\n';
  return 0;
}