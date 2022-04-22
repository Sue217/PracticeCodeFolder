#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  vector<tuple<string, int, double>> a;
  while (tt--) {
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      m[x] += 1;
    }
    int kinds = (int) m.size();
    double avg = 0.0;
    for (auto& it : m) {
      avg += it.second;
    }
    avg /= (double) kinds;
    a.emplace_back(s, kinds, avg);
  }
  sort(a.begin(), a.end(), [&](auto x, auto y) {
    if (get<1>(x) == get<1>(y)) {
      return get<2>(x) < get<2>(y);
    }
    return get<1>(x) > get<1>(y);
  });
  if (a.size() == 0) {
    cout << "- - -" << '\n';
  } else
  if (a.size() == 1) {
    cout << get<0>(a[0]) << " - -" << '\n';
  } else
  if (a.size() == 2) {
    cout << get<0>(a[0]) << " " << get<0>(a[1]) << " -" << '\n';
  } else {
    cout << get<0>(a[0]) << " " << get<0>(a[1]) << " " << get<0>(a[2]) << '\n';
  }
  return 0;
}