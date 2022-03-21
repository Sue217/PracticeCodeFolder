/**
 *    author: subobo
 *    created: 29.01.2022 15:00:36
**/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class dsu {
 public:
  vector<int> p;
  vector<pair<int, int>> d;
  vector<bool> required;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    d.resize(n);
    required.resize(n);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
    }
  }

  inline bool is_united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  vector<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    d.d[i] = make_pair(x, y);
  }
  auto dist = [&](pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
  };
  char ops;
  while (cin >> ops) {
    if (ops == 'O') {
      int x;
      cin >> x;
      d.required[x] = true;
      for (int it = 1; it <= n; it++) {
        if (d.required[it] && dist(d.d[it], d.d[x]) <= m) {
          d.unite(x, it);
        }
      }
    } else {
      int x, y;
      cin >> x >> y;
      if (d.is_united(x, y)) {
        puts("SUCCESS");
      } else {
        puts("FAIL");
      }
    }
  }
  return 0;
}