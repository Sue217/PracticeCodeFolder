/**
 *    author: subobo
 *    created: 09.03.2022 21:14:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 20, M = 21;
  // int N, M;
  // cin >> N >> M;
  vector<vector<bool>> g(N, vector<bool>(M));
  long long ans = 0;
  vector<pair<int, int>> point;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      point.emplace_back(i, j);
    }
  }
  function<int(int, int)> gcd = [&](int x, int y) {
    return y ? gcd(y, x % y) : x;
  };
  int n = (int) point.size();
  set<array<int, 3>> dir;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto from = point[i], to = point[j];
      int x1 = point[i].first, y1 = point[i].second, x2 = point[j].first, y2 = point[j].second;
      int A = -(y1 - y2), B = x1 - x2, C = x2 * (y1 - y2) - y2 * (x1 - x2);
      int G = gcd(gcd(A, B), C);
      dir.insert({A / G, B / G, C / G});
    }
  }
  cout << dir.size() << '\n';
  return 0;
}