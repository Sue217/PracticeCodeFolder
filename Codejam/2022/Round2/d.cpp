/**
 *    author:  tourist
 *    created: 14.05.2022 19:38:45       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

long long Solve(vector<pair<int, int>> a, int c) {
  sort(a.begin(), a.end());
  int n = (int) a.size();
  vector<int> bal(n + 1);
  for (int i = 0; i < n; i++) {
    bal[i + 1] = bal[i] + (a[i].second == 1 ? 1 : -1);
  }
  vector<vector<long long>> pref(2, vector<long long>(n + 1));
  for (int r = 0; r < 2; r++) {
    for (int i = 0; i < n; i++) {
      pref[r][i + 1] = pref[r][i];
      if (a[i].second == r) {
        pref[r][i + 1] += a[i].first;
      }
    }
  }
  map<int, int> mp;
  mp[0] = 0;
  vector<long long> f(n + 1);
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] + 2 * a[i - 1].first;
    if (i >= 2) {
      f[i] = min(f[i], f[i - 2] + 2 * a[i - 1].first + c);
    }
    if (mp.find(bal[i]) != mp.end()) {
      int j = mp[bal[i]];
      int r = a[i - 1].second;
      f[i] = min(f[i], f[j] + 2 * (pref[r][i] - pref[r][j]));
    }
    mp[bal[i]] = i;
  }
  return f[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> pos;
    vector<pair<int, int>> neg;
    for (int i = 0; i < n; i++) {
      int x, v;
      cin >> x >> v;
      if (x > 0) {
        pos.emplace_back(x, v);
      }
      if (x < 0) {
        neg.emplace_back(-x, v);
      }
    }
    cout << Solve(pos, c) + Solve(neg, c) << '\n';
  }
  return 0;
}
