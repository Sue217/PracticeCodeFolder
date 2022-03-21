/*
ID: sujingb1
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;

inline vector<string> reflection(vector<string> init) {
  auto ans = init;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      swap(ans[i][j], ans[i][n - j - 1]);
    }
  }
  return ans;
}

inline vector<string> rotation90(vector<string> init) {
  auto ans = init;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(ans[i][j], ans[j][i]);
    }
  }
  ans = reflection(ans);
  return ans;
}

inline vector<string> rotation180(vector<string> init) {
  auto ans = init;
  ans = rotation90(ans);
  ans = rotation90(ans);
  return ans;
}

inline vector<string> rotation270(vector<string> init) {
  auto ans = init;
  ans = rotation180(ans);
  ans = rotation90(ans);
  return ans;
}

int main() {
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");
  fin >> n;
  vector<string> init(n), res(n);
  for (string& in : init) {
    fin >> in;
  }
  for (string& in : res) {
    fin >> in;
  }
  if (res == rotation90(init)) {
    fout << 1 << '\n';
  } else
  if (res == rotation180(init)) {
    fout << 2 << '\n';
  } else
  if (res == rotation270(init)) {
    fout << 3 << '\n';
  } else
  if (res == reflection(init)) {
    fout << 4 << '\n';
  } else
  if (res == rotation90(reflection(init))
   || res == rotation180(reflection(init))
   || res == rotation270(reflection(init))) {
     fout << 5 << '\n';
  } else
  if (res == init) {
    fout << 6 << '\n';
  } else {
    fout << 7 << '\n';
  }
  return 0;
}