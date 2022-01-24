/**
 *    author: subobo
 *    created: 24.01.2022 23:33:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  string op;
  int times = 0;
  while (cin >> op, op != "End") {
    if (times == k) {
      cout << op << '\n';
      times = 0;
      continue;
    }
    if (op == "ChuiZi") {
      cout << "Bu" << '\n';
    } else
    if (op == "JianDao") {
      cout << "ChuiZi" << '\n';
    } else
    if (op == "Bu") {
      cout << "JianDao" << '\n';
    }
    times += 1;
  }
  return 0;
}