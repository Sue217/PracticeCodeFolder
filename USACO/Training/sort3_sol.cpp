/*
  ID: sujingb1
  TASK: sort3
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("sort3.in");
  ofstream fout ("sort3.out");
  int n;
  fin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    fin >> a[i];
    --a[i];
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  vector<vector<int>> edge(3, vector<int>(3));
  for (int i = 0; i < n; i++) {
    edge[a[i]][b[i]] += 1;
  }
  int self = 0;
  for (int i = 0; i < 3; i++) {
    self += edge[i][i];
  }
  int ans = self;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      int mn = min(edge[i][j], edge[j][i]);
      ans += mn;
      edge[i][j] -= mn;
      edge[j][i] -= mn;
    }
  }
  ans += max(edge[0][1], edge[1][0]);
  fout << n - ans << '\n';
  return 0;
}