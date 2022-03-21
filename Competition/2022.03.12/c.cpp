/**
 *    author: subobo
 *    created: 12.03.2022 15:40:33
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
    vector<int> a(n), b(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (s.count(b[i]) == 0) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    int l, r;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (b[i] == a[j]) {
          l = j;
          r = i;
          if (l <= r) {
            break;
          }
        }
      }
      // debug(l, r);
      if (l == r) {
        continue;
      }
      for (int k = l; k < r; k++) {
        cout << k + 1 << " " << k + 2 << '\n';
        // debug(k, a[k], a[k + 1]);
        swap(a[k], a[k + 1]);
      }
    }
    // for (auto i : a) cerr << i << " ";
    // cerr << '\n';
    cout << 0 << " " << 0 << '\n';
  }
  return 0;
}