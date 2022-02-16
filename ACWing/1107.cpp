/**
 *    author: subobo
 *    created: 15.02.2022 21:22:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string start = "12345678", finish = "";
  for (int i = 0; i < 8; i++) {
    char c;
    cin >> c;
    finish += c;
  }
  auto A = [&](string s) {
    string ss = s;
    reverse(ss.begin(), ss.end());
    return ss;
  };
  auto B = [&](string s) {
    string ss = s;
    ss[0] = s[3];
    ss[7] = s[4];
    for (int i = 1, j = 4, k = 0, l = 5; k < 3; i++, j++, k++, l++) {
      ss[i] = s[k];
      ss[j] = s[l];
    }
    return ss;
  };
  auto C = [&](string s) {
    swap(s[1], s[2]);
    swap(s[5], s[6]);
    swap(s[1], s[5]);
    return s;
  };
  unordered_map<string, int> step;
  unordered_map<string, char> path;
  unordered_map<string, string> mp;
  queue<string> q;
  q.push(start);
  step[start] = 0;
  mp[start] = start;
  path[start] = 'N';
  while (!q.empty()) {
    string status = q.front();
    q.pop();
    int d = step[status] + 1;
    string s = A(status);
    if (step.count(s) == 0) {
      step[s] = d;
      mp[s] = status;
      path[s] = 'A';
      q.push(s);
    }
    s = B(status);
    if (step.count(s) == 0) {
      step[s] = d;
      mp[s] = status;
      path[s] = 'B';
      q.push(s);
    }
    s = C(status);
    if (step.count(s) == 0) {
      step[s] = d;
      mp[s] = status;
      path[s] = 'C';
      q.push(s);
    }
  }
  cout << step[finish] << '\n';
  string s = finish, res = "";
  while (path[s] != 'N') {
    res += path[s];
    s = mp[s];
  }
  reverse(res.begin(), res.end());
  cout << res;
  return 0;
}