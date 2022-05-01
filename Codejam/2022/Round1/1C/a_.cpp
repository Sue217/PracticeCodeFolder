#include <bits/stdc++.h>

using namespace std;

vector<int> a[256];
int test, n, in[256], out[256], c[1001], tot, f[256], v[256], r[256], w[101];
string str[101];

bool check(string s) {
  int n = s.size();
  bool b[256];
  memset(b, false, sizeof(b));
  for (int i = 0; i < n; i++)
    if (!i || s[i] != s[i - 1])
      if (b[s[i]])
        return false;
      else
        b[s[i]] = true;
  return true;
}

inline void solve() {
  for (int i = 0; i < 256; i++) a[i].clear(), in[i] = out[i] = v[i] = 0;
  scanf("%d", &n);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
    int x = str[i][0], y = str[i][str[i].size() - 1];
    if (x == y)
      a[x].push_back(i);
    else {
      v[x] = y;
      r[x] = i;
      ++out[x];
      ++in[y];
      if (out[x] == 2 || in[y] == 2) {
        ok = false;
      }
    }
  }
  if (!ok) {
    printf("IMPOSSIBLE\n");
    return;
  }
  string ans = "";
  int cnt = 0;
  for (int i = 0; i < 256; i++)
    if (!in[i] && !out[i]) {
      for (auto x : a[i]) ans += str[x], ++cnt;
    } else if (out[i] && !in[i]) {
      for (int j = i;;) {
        for (auto x : a[j]) ans += str[x], ++cnt;
        int k = v[j];
        if (!k || k == i) break;
        ans += str[r[j]];
        ++cnt;
        j = k;
      }
    }
  if (cnt != n) {
    printf("IMPOSSIBLE\n");
    return;
  }
  if (check(ans))
    cout << ans << endl;
  else {
    printf("IMPOSSIBLE\n");
    return;
  }
}

int main() {
  scanf("%d", &test);
  for (int uu = 1; uu <= test; uu++) {
    printf("Case #%d: ", uu);
    solve();
  }
}