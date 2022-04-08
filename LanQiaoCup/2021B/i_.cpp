/**
 *    author: subobo
 *    created: 08.04.2022 21:46:26
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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> s;
  while (m--) {
    int p, q;
    cin >> p >> q;
    --q;
    if (p == 0) {
      while (!s.empty() && s.back().first == 0) {
        q = max(q, s.back().second);
        s.pop_back();
      }
      int ptr = (int) s.size();
      while (ptr >= 2 && s[ptr - 2].second <= q) {
        s.pop_back();
        s.pop_back();
        ptr -= 2;
      }
      s.emplace_back(p, q);
    } else
    if (p == 1) {
      // assert(!s.empty());
      while (!s.empty() && s.back().first == 1) {
        q = min(q, s.back().second);
        s.pop_back();
      }
      int ptr = (int) s.size();
      while (ptr >= 2 && s[ptr - 2].second >= q) {
        s.pop_back();
        s.pop_back();
        ptr -= 2;
      }
      s.emplace_back(p, q);
    }
  }
  int itr = n;
  int low = 0, high = n - 1;
  bool empty = false;
  vector<int> ans(n);
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i].first == 0) {
      while (high > s[i].second && low <= high) {
        ans[high--] = itr--;
      }
    }
    if (s[i].first == 1) {
      while (low < s[i].second && low <= high) {
        ans[low++] = itr--;
      }
    }
    if (low > high) {
      empty = true;
      break;
    }
  }
  if (!empty) {
    if ((int) s.size() % 2 == 1) {
      while (low <= high) {
        ans[high--] = itr--;
      }
    } else {
      while (low <= high) {
        ans[low++] = itr--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}