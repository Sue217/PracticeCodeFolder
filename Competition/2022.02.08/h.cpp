/**
 *    author: subobo
 *    created: 08.02.2022 17:37:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string xa, xb;
  cin >> n >> xa >> xb;
  queue<int> q[26];
  for (int i = 0; i < n; i++) {
    q[xa[i] - 'A'].push(i);
  }
  vector<int> pos;
  for (int i = 0; i < n; i++) {
    int t = xb[i] - 'A';
    pos.emplace_back(q[t].front());
    q[t].pop();
  }
  function<long long(int, int)> Merge = [&](int left, int right)->long long {
    if (left >= right) {
      return 0;
    }
    int mid = (left + right) >> 1;
    long long ans = Merge(left, mid) + Merge(mid + 1, right);
    int i = left, j = mid + 1;
    vector<int> tt;
    while (i <= mid && j <= right) {
      if (pos[i] <= pos[j]) {
        tt.emplace_back(pos[i++]);
      } else {
        ans += mid - i + 1;
        tt.emplace_back(pos[j++]);
      }
    }
    while (i <= mid) {
      tt.emplace_back(pos[i++]);
    }
    while (j <= right) {
      tt.emplace_back(pos[j++]);
    }
    for (int i = left, j = 0; i <= right; i++, j++) {
      pos[i] = tt[j];
    }
    return ans;
  };
  long long ans = Merge(0, n - 1);
  cout << ans << '\n';
  return 0;
}