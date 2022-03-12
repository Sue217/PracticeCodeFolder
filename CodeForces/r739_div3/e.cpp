/**
 *    author: subobo
 *    created: 12.03.2022 09:48:52
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string t;
    cin >> t;
    int n = (int) t.size();
    map<char, int> m;
    string d;
    for (int i = n - 1; i >= 0; i--) {
      if (m.count(t[i]) == 0) {
        d = t[i] + d;
      }
      m[t[i]] += 1;
    }
    int sum = 0;
    bool ok = true;
    n = (int) d.size();
    for (int i = 0; i < n; i++) {
      // debug(d[i], m[d[i]], i + 1);
      if (m[d[i]] % (i + 1) != 0) {
        ok = false;
      }
      sum += m[d[i]] / (i + 1);
    }
    // debug(sum);
    string sub = t.substr(0, sum);
    string xs = "";
    set<int> s;
    for (int i = 0; i < n; i++) {
      for (char c : sub) {
        if (s.count(c) == 0) {
          xs += c;
        }
      }
      s.insert(d[i]);
    }
    if (ok && xs == t) {
      cout << sub << " " << d << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}