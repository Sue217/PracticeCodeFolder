/**
 *    author: Jingbo Su
 *    created: 27.05.2022
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vector<int> kmp(const string& s, const string& t) {
  int n = (int) s.size();
  int m = (int) t.size();
  vector<int> ne(n);
  for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && t[i] != t[j]) j = ne[j - 1];
    if (t[i] == t[j]) ++j;
    ne[i] = j;
  }
  vector<int> pos;
  for (int i = 0, j = 0; i < n; i++) {
    while (j > 0 && s[i] != t[j]) j = ne[j - 1];
    if (s[i] == t[j]) ++j;
    if (j >= m) {
      pos.push_back(i - m + 1);
      j = ne[j - 1];
    }
  }
  return pos;
}

int manacher(const string& s) {
  int n = (int) s.size();
  string t("*");
  vector<int> p(n + n + 1);
  for (int i = 0; i < n; i++) {
    t += s[i];
    t += '*';
  }
  int m = -1, r = -1;
  for (int i = 0; i <= (int) t.size(); i++) {
    if (i > r) {
      p[i] = 1;
    } else {
      p[i] = min(p[m + m - i], r - i + 1);
    }
    while (0 <= i - p[i] && i + p[i] <= (int) t.size() && t[i - p[i]] == t[i + p[i]]) {
      p[i] += 1;
    }
    if (i + p[i] - 1 > r) {
      m = i;
      r = i + p[i] - 1;
    }
  }
  return *max_element(p.begin(), p.end()) - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  auto ans = kmp(s, t);
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " \n"[i == (int) ans.size() - 1];
  }
  // string s;
  // cin >> s;
  // cout << manacher(s) << '\n';
  return 0;
}