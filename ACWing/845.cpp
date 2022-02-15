/**
 *    author: subobo
 *    created: 15.02.2022 21:54:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string start = "", finish = "12345678x";
  for (int i = 0; i < 9; i++) {
    char c;
    cin >> c;
    start += c;
  }
  array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  unordered_map<string, int> step;
  queue<string> q;
  q.push(start);
  step[start] = 0;
  while (!q.empty()) {
    string net = q.front();
    q.pop();
    if (net == finish) {
      cout << step[net] << '\n';
      return 0;
    }
    int d = step[net];
    int pos = (int) net.find('x');
    int x = pos / 3, y = pos % 3;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {
        string s = net;
        swap(s[pos], s[xx * 3 + yy]);
        if (step.count(s) == 0) {
          step[s] = d + 1;
          q.push(s);
        }
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}