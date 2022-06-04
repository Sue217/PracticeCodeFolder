/**
 *    author: subobo
 *    created: 03.06.2022 10:51:09
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  int n, m;
  cin >> n >> m;
  auto ptr = make_shared<vector<vector<int>>> (n);
  cout << ptr.unique() << endl;
  cout << ptr.use_count() << endl;
  cout << ptr->empty() << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      (*ptr)[i].push_back(x);
    }
  }
  cout << ptr.unique() << endl;
  cout << ptr.use_count() << endl;
  cout << ptr->empty() << endl;
  debug(*ptr);
  return 0;
}