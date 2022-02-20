/*
ID: sujingb1
TASK: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  int m, s, c;
  fin >> m >> s >> c;
  vector<pair<int, int>> stall(1, make_pair(0, 0));
  vector<int> v(c);
  for (int& in : v) {
    fin >> in;
  }
  sort(v.begin(), v.end());
  int st = v.front(), ed = v.back();
  for (int it : v) {
    stall.emplace_back(it, it - stall.back().first);
  }
  if (c > 0) {
    stall[1].second = 0;
  }
  sort(stall.begin(), stall.end(), [](const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
  });
  int ans = 0;
  for (int i = 0; i < m - 1; i++) {
    ans += stall[i].second - 1;
  }
  ans = ed - st + 1 - ans;
  if (m >= c) {
    ans = c;
  }
  fout << ans << '\n';
  return 0;
}