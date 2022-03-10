/**
 *    author: subobo
 *    created: 10.03.2022 09:44:56
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
    int n, k;
    cin >> n >> k;
    vector<int> a;
    while (n) {
      a.push_back(n % 10);
      n /= 10;
    }
    int m = (int) a.size();
    reverse(a.begin(), a.end());
    vector<int> num(10);
    function<bool(int, int, int, int)> Dfs = [&](int bit, int greater, int has, int v) {
      if (bit == m) {
        cout << v << '\n';
        return true;
      }
      for (int i = greater ? 0 : a[bit]; i < 10; i++) {
        // debug(i, num[i]);
        num[i] += 1;
        int cnt = has;
        if (num[i] == 1) {
          cnt += 1;
        }
        if (cnt > k) {
          num[i] -= 1;
          continue;
        }
        // debug(v, cnt);
        if (Dfs(bit + 1, greater | (i > a[bit]), cnt, v * 10 + i)) {
          return true;
        }
        num[i] -= 1;
      }
      return false;
    };
    Dfs(0, 0, 0, 0);
  }
  return 0;
}