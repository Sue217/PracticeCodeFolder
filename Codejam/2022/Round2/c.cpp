/**
 *    author:  tourist
 *    created: 14.05.2022 19:15:23       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }

  friend T vmul(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }

  inline T abs2() const {
    return x * x + y * y;
  }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};

using Point = TPoint<long long>;
//using Point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

class matching {
 public:
  vector<vector<int>> g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;

  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was = vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }

  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }

  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }

  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
    }
    Point r;
    cin >> r.x >> r.y;
    vector<Point> q(n);
    for (int i = 0; i < n; i++) {
      cin >> q[i].x >> q[i].y;
    }
    vector<vector<int>> order(n);
    matching mat(n, n);
    for (int i = 0; i < n; i++) {
      auto dr = (p[i] - r).abs2();
      vector<pair<long long, int>> all;
      for (int j = 0; j < n; j++) {
        auto d = (p[i] - q[j]).abs2();
        if (d <= dr) {
          all.emplace_back(d, j);
        }
      }
      sort(all.begin(), all.end());
      order[i].reserve(all.size());
      for (auto& y : all) {
        order[i].push_back(y.second);
        mat.add(i, y.second);
      }
    }
    if (mat.solve() < n) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    cout << "POSSIBLE" << '\n';
    vector<bool> child(n, true);
    vector<bool> sweet(n, true);
    vector<int> ptr(n, 0);
    for (int iter = 0; iter < n; iter++) {
      vector<int> to(n);
      for (int i = 0; i < n; i++) {
        if (!child[i]) {
          continue;
        }
        while (ptr[i] < (int) order[i].size() && !sweet[order[i][ptr[i]]]) {
          ptr[i] += 1;
        }
        assert(ptr[i] < (int) order[i].size());
        to[i] = order[i][ptr[i]];
      }
      vector<int> seq;
      int x = 0;
      while (!child[x]) {
        x += 1;
      }
      vector<bool> seen(n, false);
      seq.push_back(x);
      seen[x] = true;
      while (true) {
        x = mat.pb[to[x]];
        seq.push_back(x);
        if (seen[x]) {
          break;
        }
        seen[x] = true;
      }
      if (seq.back() != seq[seq.size() - 2]) debug(seq);
      for (int i = (int) seq.size() - 1; i >= 0; i--) {
        if (i < (int) seq.size() - 1 && seq[i] == x) {
          break;
        }
        mat.pa[seq[i]] = to[seq[i]];
        mat.pb[mat.pa[seq[i]]] = seq[i];
      }
      assert(child[x] && sweet[to[x]]);
      cout << x + 1 << " " << to[x] + 2 << '\n';
      child[x] = false;
      sweet[to[x]] = false;
    }
  }
  return 0;
}
