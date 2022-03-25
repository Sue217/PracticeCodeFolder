/**
 *    author: Jingbo Su
 *    created: 22.01.2022
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p; // d, sz
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    // d.resize(n);
    // sz.assign(n, 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
    // if (x != p[x]) {
    //   int root = get(p[x]);
    //   d[x] += d[p[x]];
    //   p[x] = root;
    // }
    // return p[x];
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }

  // dist = abs(d[x] - d[y])...
};
