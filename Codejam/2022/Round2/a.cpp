/**
 *    author:  tourist
 *    created: 14.05.2022 18:33:44       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1 || k < n - 1) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    auto GetXY = [&](int id) {
      id -= 1;
      int x = 0, y = 0;
      int sz = n;
      while (sz > 1) {
        if (id < sz - 1) {
          return make_pair(x, y + id);
        }
        id -= sz - 1;
        y += sz - 1;
        if (id < sz - 1) {
          return make_pair(x + id, y);
        }
        id -= sz - 1;
        x += sz - 1;
        if (id < sz - 1) {
          return make_pair(x, y - id);
        }
        id -= sz - 1;
        y -= sz - 1;
        if (id < sz - 1) {
          return make_pair(x - id, y);
        }
        id -= sz - 1;
        x -= sz - 2;
        y += 1;
        sz -= 2;
      }
      return make_pair(x, y);
    };
    auto GetId = [&](pair<int, int> p) {
      int x = p.first;
      int y = p.second;
      int skip = min(min(x, n - 1 - x), min(y, n - 1 - y));
      int res = n * n - (n - 2 * skip) * (n - 2 * skip) + 1;
      if (x == skip) {
        return res + (y - skip);
      }
      res += n - 2 * skip - 1;
      if (n - 1 - y == skip) {
        return res + (x - skip);
      }
      res += n - 2 * skip - 1;
      if (n - 1 - x == skip) {
        return res + (n - 1 - skip) - y;
      }
      res += n - 2 * skip - 1;
      assert(y == skip);
      return res + (n - 1 - skip) - x;
    };
    int low = 1, high = n * n;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      auto p = GetXY(mid);
      int steps = (mid - 1) + abs(p.first - n / 2) + abs(p.second - n / 2);
      if (steps <= k) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    vector<pair<int, int>> shortcuts;
    auto Add = [&](int i, int j) {
      if (i + 1 < j) {
        shortcuts.emplace_back(i, j);
      }
      return i < j;
    };
    auto p = GetXY(low);
    while (p.first != n / 2 || p.second != n / 2) {
      while (p.first < n / 2) {
        auto q = p;
        q.first += 1;
        if (!Add(GetId(p), GetId(q))) {
          break;
        }
        p = q;
      }
      while (p.first > n / 2) {
        auto q = p;
        q.first -= 1;
        if (!Add(GetId(p), GetId(q))) {
          break;
        }
        p = q;
      }
      while (p.second < n / 2) {
        auto q = p;
        q.second += 1;
        if (!Add(GetId(p), GetId(q))) {
          break;
        }
        p = q;
      }
      while (p.second > n / 2) {
        auto q = p;
        q.second -= 1;
        if (!Add(GetId(p), GetId(q))) {
          break;
        }
        p = q;
      }
    }
    cout << shortcuts.size() << '\n';
    for (auto& pp : shortcuts) {
      cout << pp.first << " " << pp.second << '\n';
    }
  }
  return 0;
}
