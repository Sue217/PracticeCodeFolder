/*
ID: sujingb1
TASK: milk
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");int n, m;
  fin >> n >> m;
  vector<pair<int, int>> milk;
  for (int i = 0; i < m; i++) {
    int p, a;
    fin >> p >> a;
    milk.emplace_back(p, a);
  }
  sort(milk.begin(), milk.end(), [](pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  int tot = n, ans = 0;
  for (auto it : milk) {
    if (tot <= 0) {
      break;
    }
    int cnt = it.second <= tot ? it.second : tot;
    tot -= cnt;
    ans += it.first * cnt;
  }
  fout << ans << '\n';
  return 0;
}