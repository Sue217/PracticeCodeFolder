/*
ID: sujingb1
TASK: crypt1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  int n;
  fin >> n;
  set<int> dir;
  for (int i = 0; i < n; i++) {
    int x;
    fin >> x;
    dir.insert(x);
  }
  auto get_digit = [&](int x) {
    while (x) {
      if (dir.find(x % 10) == dir.end()) {
        return false;
      }
      x /= 10;
    }
    return true;
  };
  auto get_digit_num = [&](int x) {
    int tot = 0;
    while (x) {
      tot += 1;
      x /= 10;
    }
    return tot;
  };
  int ans = 0;
  for (int fst = 100; fst <= 999; fst++) {
    for (int sec = 10; sec <= 99; sec++) {
      if (get_digit(fst) && get_digit(sec) &&
          get_digit(fst * (sec / 10)) && get_digit_num(fst * (sec / 10)) == 3 &&
          get_digit(fst * (sec % 10)) && get_digit_num(fst * (sec % 10)) == 3 &&
          get_digit(fst * sec) && get_digit_num(fst * sec) == 4) {
        // cerr << fst << " " << sec << " " << fst * sec << '\n';
        ans += 1;
      }
    }
  }
  fout << ans << '\n';
  return 0;
}