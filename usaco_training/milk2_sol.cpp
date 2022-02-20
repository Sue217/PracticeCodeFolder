/*
ID: sujingb1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");
  int n;
  fin >> n;
  vector<pair<int, int>> milk;
  for (int i = 0; i < n; i++) {
    int st, ed;
    fin >> st >> ed;
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
  fout << milking << " " << idle << '\n';
  return 0;
}