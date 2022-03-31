/*
  ID: sujingb1
  TASK: pprime
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("pprime.in");
  ofstream fout ("pprime.out");
  int a, b;
  fin >> a >> b;
  const int N = 10000001;
  bitset<N> used;
  vector<int> p;
  for (int d = 2; d <= N; d++) {
    if (!used[d]) {
      p.push_back(d);
    }
    for (int cc = 0; p[cc] <= N / d; cc++) {
      used[p[cc] * d] = 1;
      if (d % p[cc] == 0) {
        break;
      }
    }
  }
  for (int it : p) {
    if (it >= a && it <= b) {
      string s = to_string(it);
      string res(s);
      reverse(s.begin(), s.end());
      if (s == res) {
        fout << s << '\n';
      }
    }
  }
  return 0;
}