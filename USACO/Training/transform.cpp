/**
 *    author: subobo
 *    created: 05.02.2022 18:39:09
**/
#include <bits/stdc++.h>

using namespace std;

int n;

inline vector<string> reflection(vector<string> init) {
  auto ans = init;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      swap(ans[i][j], ans[i][n - j - 1]);
    }
  }
  return ans;
}

inline vector<string> rotation90(vector<string> init) {
  auto ans = init;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(ans[i][j], ans[j][i]);
    }
  }
  ans = reflection(ans);
  return ans;
}

inline vector<string> rotation180(vector<string> init) {
  auto ans = init;
  ans = rotation90(ans);
  ans = rotation90(ans);
  return ans;
}

inline vector<string> rotation270(vector<string> init) {
  auto ans = init;
  ans = rotation180(ans);
  ans = rotation90(ans);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<string> init(n), res(n);
  for (string& in : init) {
    cin >> in;
  }
  for (string& in : res) {
    cin >> in;
  }
  if (res == rotation90(init)) {
    cout << 1 << '\n';
  } else
  if (res == rotation180(init)) {
    cout << 2 << '\n';
  } else
  if (res == rotation270(init)) {
    cout << 3 << '\n';
  } else
  if (res == reflection(init)) {
    cout << 4 << '\n';
  } else
  if (res == rotation90(reflection(init))
   || res == rotation180(reflection(init))
   || res == rotation270(reflection(init))) {
     cout << 5 << '\n';
  } else
  if (res == init) {
    cout << 6 << '\n';
  } else {
    cout << 7 << '\n';
  }
  return 0;
}