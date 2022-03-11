/**
 *    author: subobo
 *    created: 11.03.2022 09:07:49
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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> suf(q);
  vector<pair<int, int>> modify(q, make_pair(-1, -1));
  for (int t = 0; t < q; t++) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      --x;
      modify[t] = make_pair(x, y);
    } else {
      cin >> y;
      suf[t] = y;
    }
  }
  for (int i = q - 2; i >= 0; i--) {
    suf[i] = max(suf[i], suf[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    a[i] = max(a[i], suf[0]);
  }
  for (int t = 0; t < q; t++) {
    if (modify[t].first != -1 && modify[t].second != -1) {
      a[modify[t].first] = max(modify[t].second, suf[t]);
      // debug(modify[t].second, suf[t]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}