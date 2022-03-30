/*
  ID: sujingb1
  TASK: ariprog
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
  int n, m;
  fin >> n >> m;
  vector<bool> sq(m * m * 2 + 1);
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      sq[i * i + j * j] = true;
    }
  }
  vector<pair<int, int>> p;
  for (int a = 0; a <= m * m - n + 1; a++) {
    for (int b = 1; a + (n - 1) * b <= m * m * 2; b++) {
      bool ok = true;
      for (int c = 0; c < n; c++) {
        if (!sq[a + b * c]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        p.emplace_back(a, b);
      }
    }
  }
  sort(p.begin(), p.end(), [&](auto a, auto b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });
  if (p.size() == 0) {
    fout << "NONE" << '\n';
  } else {
    for (auto it : p) {
      fout << it.first << " " << it.second << '\n';
    }
  }
  return 0;
}