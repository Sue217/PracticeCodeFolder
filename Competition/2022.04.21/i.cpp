#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  map<string, int> m;
  for (int i = 0; i < n / c; i++) {
    vector<int> a(c);
    for (int j = 0; j < c; j++) {
      cin >> a[j];
    }
    reverse(a.begin(), a.end());
    for (int j = 0; j < c; j++) {
      m[s[i * c + j]] = a[j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (m.count(s) == 0) {
      cout << "Wrong Number" << '\n';
    } else {
      cout << m[s] << '\n';
    }
  }
  return 0;
}