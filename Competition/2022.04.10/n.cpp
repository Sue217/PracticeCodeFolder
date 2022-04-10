/**
 *    author: subobo
 *    created: 10.04.2022 13:41:26
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  bitset<21> used;
  vector<int> chain;
  function<bool(int)> Dfs = [&](int start) {
    int has = (int) chain.size();
    if (has == n) {
      if (g[chain.back()][chain.front()] == 'W' || g[chain.front()][chain.back()] == 'L') {
        return true;
      } else {
        return false;
      }
    }
    bool can = false;
    for (int d = start; d < n; d++) {
      if (used[d] == 0 && (g[d][start] == 'W' || g[start][d] == 'L')) {
        can = true;
        break;
      }
    }
    if (!can) {
      return false;
    }
    for (int d = start; d < n; d++) {
      if (used[d] == 0 && (g[chain.back()][d] == 'W' || g[d][chain.back()] == 'L')) {
        used[d] = 1;
        chain.push_back(d);
        if (Dfs(start)) return true;
        used[d] = 0;
        chain.pop_back();
      }
    }
    return false;
  };
  for (int i = 0; i < n; i++) {
    used[i] = 1;
    chain.push_back(i);
    if (Dfs(i)) {
      for (int j = 0; j < n; j++) {
        cout << chain[j] + 1 << " \n"[j == n - 1];
      }
      return 0;
    }
    used[i] = 0;
    chain.pop_back();
  }
  cout << "NO Solution" << '\n';
  return 0;
}