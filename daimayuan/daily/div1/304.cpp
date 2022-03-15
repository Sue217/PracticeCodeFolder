/**
 *    author: subobo
 *    created: 15.03.2022 23:33:04
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      vector<int> div;
      for (int j = 0; j < n; j++) {
        if (a[j] >= a[i]) {
          div.push_back(a[j] - a[i]);
        }
      }
      if ((int) div.size() < n / 2) {
        continue;
      }
      set<int> s;
      int cnt = 0;
      for (int it : div) {
        if (it == 0) {
          ++cnt;
        } else {
          for (int p = 2; p <= it / p; p++) {
            if (it % p == 0) {
              s.insert(p);
              s.insert(it / p);
            }
          }
        }
      }
      if (n / 2 <= cnt) {
        break;
      }
      for (auto it = s.rbegin(); it != s.rend(); it++) {
        debug(*it);
        int cnt = 0;
        for (int d : div) {
          if (d % *it == 0) {
            ++cnt;
          }
        }
        if (n / 2 <= cnt) {
          ans = max(ans, *it);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}