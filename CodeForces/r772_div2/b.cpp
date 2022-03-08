/**
 *    author: subobo
 *    created: 08.03.2022 20:34:04
**/
#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& in : a) {
      cin >> in;
    }
    vector<bool> got(n);
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        got[i] = true;
      }
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (got[i]) {
        if (i + 2 < n && got[i + 2]) {
          a[i + 1] = max(a[i], a[i + 2]);
          got[i] = got[i + 2] = false;;
        } else {
          a[i] = max(a[i - 1], a[i + 1]);
          got[i] = false;
        }
        cnt += 1;
      }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}