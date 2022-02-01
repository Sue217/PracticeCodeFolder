/**
 *    author: subobo
 *    created: 01.02.2022 18:32:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> seq;
  string s;
  cin >> s;
  int v = 0, sign = 1;
  for (int i = 1; i < (int) s.size() - 1; i++) {
    char c = s[i];
    if (c == ',') {
      seq.emplace_back(v * sign);
      v = 0;
      sign = 1;
    } else
    if (c == '-') {
      sign = -1;
    } else {
      v = v * 10 + c - '0';
    }
  }
  seq.emplace_back(v * sign);
  sort(seq.begin(), seq.end(), [](int a, int b) {
    return a > b;
  });
  int smax = seq.front();
  for (int it : seq) {
    if (smax != it) {
      smax = it;
      break;
    }
  }
  cout << "max=" << *max_element(seq.begin(), seq.end()) << ", ";
  cout << "smax=" << smax;
  return 0;
}