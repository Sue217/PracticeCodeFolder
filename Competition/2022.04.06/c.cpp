/**
 *    author: subobo
 *    created: 06.04.2022 13:03:06
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, h, q;
    cin >> n >> m >> h >> q;
    set<tuple<int, int, int>> co;
    array<int, 6> dx{-1, 0, 1, 0, 0, 0}, dy{0, -1, 0, 1, 0, 0}, dz{0, 0, 0, 0, -1, 1};
    auto Bfs = [&](int x, int y, int z) {
      queue<tuple<int, int, int>> s;
      map<tuple<int, int, int>, int> dist;
      s.emplace(x, y, z);
      while (!s.empty()) {
        auto t = s.front();
        s.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int z = get<2>(t);
        for (int i = 0; i < 6; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          int zz = z + dz[i];
          if (0 <= xx && xx < n && 0 <= yy && yy < m && 0 <= zz && zz < h && dist[make_tuple(xx, yy, zz)] == 0) {
            if (co.find(make_tuple(xx, yy, zz)) != co.end()) {
              return dist[make_tuple(x, y, z)] + 1;
            }
            s.emplace(xx, yy, zz);
            dist[make_tuple(xx, yy, zz)] = dist[make_tuple(x, y, z)] + 1;
          }
        }
      }
      return -1;
    };
    while (q--) {
      int op, x, y, z;
      cin >> op >> x >> y >> z;
      --x; --y; --z;
      if (op == 1) {
        co.emplace(x, y, z);
      }
      if (op == 2) {
        cout << Bfs(x, y, z) << '\n';
      }
    }
  }
  return 0;
}