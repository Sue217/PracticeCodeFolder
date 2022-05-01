/**
 *    author: subobo
 *    created: 29.04.2022 07:54:35
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
  string xs;
  getline(cin, xs);
  string start("");
  for (char& c : xs) {
    if (c == ' ') continue;
    start += c;
  }
  static constexpr int N = 9;
  int rvs = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (start[i] != 'x' && start[j] != 'x' && start[j] < start[i]) {
        rvs += 1;
      }
    }
  }
  if (rvs % 2 == 1) {
    cout << -1 << '\n';
    return 0;
  }
  auto f = [&](string& status) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (status[i] != 'x') {
        int v = status[i] - '1';
        ans += (int) (abs(i / 3 - v / 3) + abs(i % 3 - v % 3));
      }
    }
    return ans;
  };
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> s;
  map<string, int> dist;
  map<string, string> prev;
  string finish = "12345678x";
  array<int, 4> dx{-1, 0, 1, 0};
  array<int, 4> dy{0, 1, 0, -1};
  s.emplace(f(start), start);
  dist[start] = 0;
  while (!s.empty()) {
    auto t = s.top();
    s.pop();
    if (t.second == finish) {
      break;
    }
    string now(t.second);
    string old(t.second);
    int zero = 0;
    for (int i = 0; i < N; i++) {
      if (now[i] == 'x') {
        zero = i;
        break;
      }
    }
    int x = zero / 3;
    int y = zero % 3;
    int dd = dist[now];
    for (int i = 0; i < 4; i++) {
      now = old;
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (0 <= xx && xx < 3 && 0 <= yy && yy < 3) {
        swap(now[x * 3 + y], now[xx * 3 + yy]);
        if (dist.count(now) == 0 || dd + 1 < dist[now]) {
          dist[now] = dd + 1;
          prev[now] = old;
          s.emplace(dist[now] + f(now), now);
        }
      }
    }
  }
  int ans = 0;
  while (finish != start) {
    ans += 1;
    finish = prev[finish];
  }
  cout << ans << '\n';
  cerr << "time: " << clock() << " ms" << '\n';
  return 0;
}