/**
 *    author: subobo
 *    created: 11.01.2022 15:32:23
**/
#include <bits/stdc++.h>
#pragma GCC optimize(2)

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, V;
  cin >> n >> V;
  vector<int> f(V + 1), g(V + 1), mono_que(V + 1);
  for (int i = 1; i <= n; i++) {
    g.resize(V + 1), g = f;
    int v, w, s;
    cin >> v >> w >> s;
    for (int remainder = 0; remainder < v; remainder++) {
      int head = 0, tail = -1;
      for (int k = remainder; k <= V; k += v) {
        while (head <= tail && k - mono_que[head] > s * v) {
          head++;
        }
        while (head <= tail && g[mono_que[tail]] + (k - mono_que[tail]) / v * w <= g[k]) {
          tail--;
        }
        mono_que[++tail] = k;
        f[k] = g[mono_que[head]] + (k - mono_que[head]) / v * w;
      }
    }
  }
  cout << f[V] << '\n';
  return 0;
}
