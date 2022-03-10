/**
 *    author: subobo
 *    created: 10.03.2022 14:07:41
**/
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string xs;
    int k;
    cin >> xs >> k;
    for (;;) {
      set<char> s;
      for (char c : xs) {
        s.insert(c);
      }
      if (k >= (int) s.size()) {
        cout << xs << '\n';
        break;
      }
      int n = (int) xs.size();
      s.clear();
      for (int p = 0;; p++) {
        s.insert(xs[p]);
        if ((int) s.size() > k) {
          if (xs[p] == '9') {
            --p;
          }
          xs[p] += 1;
          for (int j = p + 1; j < n; j++) {
            xs[j] = '0';
          }
          break;
        }
      }
      // debug(xs, s.size());
    }
  }
  return 0;
}