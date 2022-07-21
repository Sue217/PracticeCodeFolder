#include <bits/stdc++.h>

using namespace std;

void sr(int n, char r[]) {
  int i, m;
  for (i = 0; i < n; i++) {
    cin >> m;
    r[i] = m + '0';
  }
  r[i] = '\0';
}
void fx(char e[], char g[], char h[], char r[]) {
  int i, j, k = 0, q;
  char s[200000], t;
  for (i = 0; e[i] != '\0'; i++) {
    for (j = 0; g[j] != '\0'; j++) {
      if (g[j] == e[i]) {
        h[k] = g[j];
        k++;
        break;
      }
    }
  }
  for (i = 0; e[i] != '\0'; i++) {
    j = 0;
    if (e[i] != '1') {
      s[j] = e[i];
      j++;
    }
    if ((e[i] - '0' - 2) >= 0) {
      t = r[e[i] - '0' - 2];
      while (t != '1') {
        s[j] = t;
        j++;
        t = r[t - '0' - 2];
      }
      if (t == '1') {
        s[j] = '1';
        j++;
      }
    }
    s[j] = '\0';
    for (j = j - 1; j >= 0; j--) {
      for (q = 0; g[q] != '\0'; q++) {
        if (s[j] == g[q]) {
          break;
        }
      }
      if (g[q] != '\0') {
        break;
      }
    }
    for (; j >= 0; j--) {
      for (q = 0; q < k; q++) {
        if (s[j] == h[q]) {
          break;
        }
      }
      if (q == k) {
        h[k] = s[j];
        k++;
      }
    }
  }
  h[k] = '\0';
}
void sc(char h[], char t[]) {
  int i, j, m = 0;
  for (i = 0; h[i] != '\0'; i++) {
    for (j = 0; t[j] != '\0'; j++) {
      if (h[i] == t[j]) {
        m++;
        break;
      }
    }
  }
  cout << m << '\n';
}
void bbjj(char e[], char f[], char g[], char r[]) {
  char h[200000], t[20000];
  fx(e, g, h, r);
  fx(f, g, t, r);
  sc(h, t);
}

char r[200000];
char e[200000], f[200000], g[200000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, p, a, b, c;
  int i, j;
  cin >> m >> n >> p;
  
  for (i = 0; i < m; i++) {
    sr(n, r);
    for (j = 0; j < p; j++) {
      cin >> a >> b >> c;
      sr(a, e);
      sr(b, f);
      sr(c, g);
      bbjj(e, f, g, r);
    }
  }
  return 0;
}