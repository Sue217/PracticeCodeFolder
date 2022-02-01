/**
 *    author: subobo
 *    created: 01.02.2022 19:12:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s = "0", xs;
  cin >> xs;
  s += xs;
  int n = (int) s.size();
  vector<char> tree(100000, '#');
  int idx = 1;
  function<void(int)> build = [&](int u) {
    if (idx > n - 1) {
      return;
    }
    tree[u] = s[idx];
    if (s[idx++] != '#') {
      build(u * 2);
      build(u * 2 + 1);
    }
  };
  build(1);
  string ans = "";
  function<void(int)> inorder = [&](int u) {
    if (u > n * 2) {
      return;
    }
    inorder(u * 2);
    if (tree[u] != '#') {
      ans += tree[u];
    }
    inorder(u * 2 + 1);
  };
  inorder(1);
  cout << ans << '\n';
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}