/**
 *    author: subobo
 *    created: 09.03.2022 21:03:55
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
  map<int, int> dir;
  for (int i = 0; i < 10; i++) {
    dir[i] = 2021;
  }
  int ans = 0;
  for (int i = 1; i < 100000; i++) {
    int x = i;
    // debug(x);
    while (x) {
      if (dir[x % 10] == 0) {
        ans = i - 1;
        break;
      }
      dir[x % 10] -= 1;
      x /= 10;
    }
    if (ans != 0) {
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}