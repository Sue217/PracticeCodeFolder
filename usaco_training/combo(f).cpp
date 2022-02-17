/*
ID: sujingb1
TASK: combo
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  int n;
  fin >> n;
  array<int, 3> John, master;
  for (int i = 0; i < 3; i++) {
    fin >> John[i];
  }
  for (int i = 0; i < 3; i++) {
    fin >> master[i];
  }
  set<tuple<int, int, int>> dir;
  for (int i = John[0] - 2; i <= John[0] + 2; i++) {
    for (int j = John[1] - 2; j <= John[1] + 2; j++) {
      for (int k = John[2] - 2; k <= John[2] + 2; k++) {
        int a = i, b = j, c = k;
        while (a <= 0) {
          a += n;
        }
        while (a > n) {
          a -= n;
        }
        while (b <= 0) {
          b += n;
        }
        while (b > n) {
          b -= n;
        }
        while (c <= 0) {
          c += n;
        }
        while (c > n) {
          c -= n;
        }
        dir.insert(make_tuple(a, b, c));
      }
    }
  }
  for (int i = master[0] - 2; i <= master[0] + 2; i++) {
    for (int j = master[1] - 2; j <= master[1] + 2; j++) {
      for (int k = master[2] - 2; k <= master[2] + 2; k++) {
        int a = i, b = j, c = k;
        while (a <= 0) {
          a += n;
        }
        while (a > n) {
          a -= n;
        }
        while (b <= 0) {
          b += n;
        }
        while (b > n) {
          b -= n;
        }
        while (c <= 0) {
          c += n;
        }
        while (c > n) {
          c -= n;
        }
        dir.insert(make_tuple(a, b, c));
      }
    }
  }
  fout << (int) dir.size() << '\n';
  return 0;
}