/**
 *    author: Jingbo Su
 *    created: 22.01.2022
**/
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class fenwick {
 public:
  vector<T> fenw; // psum
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
    // psum.resize(n);
  }

  inline void modify(int x, T v) {
    for (int i = x; i <= n; i += (i & -i)) {
      fenw[i] += v;
      // psum[i] += 1ll * x * v;
    }
  }

  inline T get(int x) {
    T v{}; // u{}
    for (int i = x; i >= 1; i -= (i & -i)) {
      v += fenw[i];
      // u += psum[i];
    }
    return v;
    // return v * (x + 1) - u;
  }

  inline void make(int n) {
    for (int i = 1; i <= n; i++) {
      fenw[i] = (i & -i);
    }
  }

  inline void set(int _n, T v) {
    fenw.assign(_n, v);
  }
};
