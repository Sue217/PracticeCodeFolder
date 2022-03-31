/**
 *    author: subobo
 *    created: 31.03.2022 12:40:57
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
  int n;
  cin >> n;
  auto isPrime = [&](int m) {
    for (int d = 2; d <= m / d; d++) {
      if (m % d == 0) {
        return false;
      }
    }
    return true;
  };
  queue<string> s;
  for (int d = 0; d < n; d++) {
    if (d == 0) {
      s.emplace("2");
      s.emplace("3");
      s.emplace("5");
      s.emplace("7");
    } else {
        auto size = s.front().size();
        while (s.front().size() == size) {
          string t = s.front();
          s.pop();
          int dd = stoi(t);
          for (int cc = 1; cc <= 9; cc += 2) {
          if (isPrime(dd * 10 + cc)) {
            s.emplace(to_string(dd * 10 + cc));
          }
        }
      }
    }
  }
  while (!s.empty()) {
    cout << s.front() << '\n';
    s.pop();
  }
  return 0;
}