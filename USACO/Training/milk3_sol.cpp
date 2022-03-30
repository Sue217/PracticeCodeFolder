/*
  ID: sujingb1
  TASK: milk3
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("milk3.in");
  ofstream fout ("milk3.out");
  int a, b, c;
  fin >> a >> b >> c;
  set<tuple<int, int, int>> st;
  st.emplace(0, 0, c);
  vector<tuple<int, int, int>> que;
  que.emplace_back(0, 0, c);
  for (int q = 0; q < (int) que.size(); q++) {
    int x = get<0>(que[q]);
    int y = get<1>(que[q]);
    int z = get<2>(que[q]);
    // x->y
    if (st.find(make_tuple(x - min(x, b - y), min(b, y + x), z)) == st.end()) {
      st.emplace(x - min(x, b - y), min(b, y + x), z);
      que.emplace_back(x - min(x, b - y), min(b, y + x), z);
    }
    // x->z
    if (st.find(make_tuple(x - min(x, c - z), y, min(c, z + x))) == st.end()) {
      st.emplace(x - min(x, c - z), y, min(c, z + x));
      que.emplace_back(x - min(x, c - z), y, min(c, z + x));
    }
    // y->x
    if (st.find(make_tuple(min(a, x + y), y - min(y, a - x), z)) == st.end()) {
      st.emplace(min(a, x + y), y - min(y, a - x), z);
      que.emplace_back(min(a, x + y), y - min(y, a - x), z);
    }
    // y->z
    if (st.find(make_tuple(x, y - min(y, c - z), min(z, z + y))) == st.end()) {
      st.emplace(x, y - min(y, c - z), min(z, z + y));
      que.emplace_back(x, y - min(y, c - z), min(z, z + y));
    }
    // z->x
    if (st.find(make_tuple(min(a, x + z), y, z - min(z, a - x))) == st.end()) {
      st.emplace(min(a, x + z), y, z - min(z, a - x));
      que.emplace_back(min(a, x + z), y, z - min(z, a - x));
    }
    // z->y
    if (st.find(make_tuple(x, min(b, y + z), z - min(z, b - y))) == st.end()) {
      st.emplace(x, min(b, y + z), z - min(z, b - y));
      que.emplace_back(x, min(b, y + z), z - min(z, b - y));
    }
  }
  vector<int> d;
  for (auto it : st) {
    if (get<0>(it) == 0 && get<1>(it) + get<2>(it) == c) {
      d.push_back(get<2>(it));
    }
  }
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  int n = (int) d.size();
  for (int i = 0; i < n; i++) {
    fout << d[i] << " \n"[i == n - 1];
  }
  return 0;
}