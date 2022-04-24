# Codeforces Global Round 20

## Log Chopping

https://codeforces.com/contest/1672/problem/A

每段能砍的次数是`x - 1`，所以累加起来看奇偶

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt += x - 1;
    }
    cout << (cnt % 2 == 1 ? "errorgorn" : "maomao90") << '\n';
  }
  return 0;
}
```

## I love AAAB

https://codeforces.com/contest/1672/problem/B

如果某一个前缀中的`B`比`A	`多就g了

特判尾巴非`B`的情况直接g

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    bool ok = true;
    if (s[n - 1] != 'B') {
      cout << "NO" << '\n';
      continue;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') ++a;
      if (s[i] == 'B') {
        ++b;
        if (b > a) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
```

## Unequal Array

https://codeforces.com/contest/1672/problem/C

只考虑第一个和最后一个相等（$a_i=a_{i-1}$）的块

特别处理相等块中只有2/3个元素的情况

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> p;
    for (int i = 1; i < n; ) {
      if (a[i] == a[i - 1]) {
        int j = i;
        while (j < n && a[j] == a[j - 1]) {
          ++j;
        }
        p.emplace_back(i - 1, j - 1);
        i = j;
      } else {
        ++i;
      }
    }
    if (p.size() == 0) {
      cout << 0 << '\n';
      continue;
    }
    int u = p[0].first;
    int v = p[0].second;
    int ans = (v - u + 1 == 3 ? 1 : max(0, v - u - 2));
    if (p.size() == 1) {
      cout << ans << '\n';
      continue;
    }
    int m = (int) p.size();
    int x = p[m - 1].first;
    int y = p[m - 1].second;
    ans += y - v;
    if (v - u + 1 == 2 || v - u + 1 == 3) {
      ans -= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
```

## Cyclic Rotation

https://codeforces.com/contest/1672/problem/D

two pointers， 数组模拟表来维护每一种数之前出现过（且没有配对）的次数

前面出现过的相同的数都可以跑到当前找到的这个数的后面去

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    int i, j;
    vector<int> extra(n);
    for (i = j = 0; i < n && j < n; ) {
      if (a[i] == b[j]) {
        if (extra[a[i]] > 0) {
          extra[a[i]] -= 1;
        } else {
          i += 1;
        }
        j += 1;
      } else {
        extra[a[i]] += 1;
        i += 1;
      }
    }
    cout << ((i < n || j < n) ? "NO" : "YES") << '\n';
  }
  return 0;
}
```

