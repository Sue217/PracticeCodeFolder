/**
 *    author: subobo
 *    created: 30.01.2022 13:48:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> presum(9, vector<int>(9));
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      cin >> presum[i][j];
      presum[i][j] += presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
    }
  }
  vector<vector<vector<vector<vector<double>>>>> dp(
    9, vector<vector<vector<vector<double>>>>(
      9, vector<vector<vector<double>>>(
        9, vector<vector<double>>(
          9, vector<double>(n + 1, -1)))));
  double X = (double) presum[8][8] / n;
  auto get = [&](int x1, int y1, int x2, int y2) {
    double sum = presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1] - X;
    return (double) sum * sum / n;
  };
  function<double(int, int, int, int, int)> find = [&](int x1, int y1, int x2, int y2, int h) {
    double& V = dp[x1][y1][x2][y2][h];
    if (V >= 0) {
      return V;
    }
    if (h == 1) {
      return V = get(x1, y1, x2, y2);
    }
    V = (double) 2e9;
    for (int x = x1; x < x2; x++) {
      V = min(V, get(x1, y1, x, y2) + find(x + 1, y1, x2, y2, h - 1));
      V = min(V, get(x + 1, y1, x2, y2) + find(x1, y1, x, y2, h - 1));
    }
    for (int y = y1; y < y2; y++) {
      V = min(V, get(x1, y1, x2, y) + find(x1, y + 1, x2, y2, h - 1));
      V = min(V, get(x1, y + 1, x2, y2) + find(x1, y1, x2, y, h - 1));
    }
    return V;
  };
  cout << fixed << setprecision(3) << sqrt(find(1, 1, 8, 8, n)) << '\n';
  return 0;
}