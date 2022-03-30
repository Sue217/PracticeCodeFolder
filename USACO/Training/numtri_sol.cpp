/*
  ID: sujingb1
  TASK: numtri
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("numtri.in");
  ofstream fout ("numtri.out");
  int n;
  fin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x;
      fin >> x;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + x);
    }
  }
  fout << *max_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}