/**
 *    author: subobo
 *    created: 21.04.2022 08:41:13
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
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0 << '\n';
    return 0;
  }
  string a, b;
  vector<string> sa, sb;
  while (cin >> a >> b) {
    sa.push_back(a);
    sb.push_back(b);
  }
  int n = (int) sa.size();
  queue<string> qh;
  queue<string> qt;
  qh.emplace(s);
  qt.emplace(t);
  map<string, int> dh;
  map<string, int> dt;
  dh[s] = dt[t] = 0;
  while (!qh.empty() && !qt.empty()) {
    if (qh.size() <= qt.size()) {
      string top = qh.front();
      qh.pop();
      for (int i = 0; i < (int) top.size(); i++) {
        for (int j = 0; j < n; j++) {
          if (top.substr(i, (int) sa[j].size()) == sa[j]) {
            string xs(top.substr(0, i) + sb[j] + top.substr(i + (int) sa[j].size()));
            if (dt.count(xs) != 0) {
              if (dh[top] + 1 + dt[xs] <= 10) {
                cout << dh[top] + 1 + dt[xs] << '\n';
                return 0;
              } else {
                continue;
              }
            }
            if (dh.count(xs) != 0) {
              continue;
            }
            qh.emplace(xs);
            dh[xs] = dh[top] + 1;
          }
        }
      }
    } else {
      string top = qt.front();
      qt.pop();
      for (int i = 0; i < (int) top.size(); i++) {
        for (int j = 0; j < n; j++) {
          if (top.substr(i, (int) sb[j].size()) == sb[j]) {
            string xs(top.substr(0, i) + sa[j] + top.substr(i + (int) sb[j].size()));
            if (dh.count(xs) != 0) {
              if (dt[top] + 1 + dh[xs] <= 10) {
                cout << dt[top] + 1 + dh[xs] << '\n';
                return 0;
              } else {
                continue;
              }
            }
            if (dt.count(xs) != 0) {
              continue;
            }
            qt.emplace(xs);
            dt[xs] = dt[top] + 1;
          }
        }
      }
    }
  }
  cout << "NO ANSWER!" << '\n';
  return 0;
}