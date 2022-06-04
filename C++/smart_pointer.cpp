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
  auto ptr = make_shared<vector<int>> ();
  cout << ptr.unique() << endl;
  cout << ptr.use_count() << endl;
  cout << ptr->empty() << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ptr->push_back(x);
  }
  cout << endl;
  cout << ptr.unique() << endl;
  cout << ptr.use_count() << endl;
  cout << ptr->empty() << endl;
  debug(*ptr);
  cout << endl;
  for (auto itr = begin(*ptr); itr != end(*ptr); itr++) {
    cout << *itr << " \n"[itr == end(*ptr)];
  }
  return 0;
}