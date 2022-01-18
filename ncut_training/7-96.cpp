/**
 *    author: subobo
 *    created: 18.01.2022 22:12:16
**/
#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 1e2 + 5;

struct student {
  string id;
  int score;
  int rank, addr, status;

  friend bool operator>(const student &s, const student &t) {
    if (s.score == t.score) return s.id < t.id;
    else return s.score > t.score;
  }
};

vector<student> addr[maxn], all;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  student St;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> St.id >> St.score;
      St.addr = i;
      addr[i].push_back(St);
    }
    sort(addr[i].begin(), addr[i].end(), greater<student>());
    for (int j = 0; j < (int) addr[i].size(); ++j) {
      if (j == 0) {
        addr[i][j].status = j + 1;
      } else
      if (addr[i][j].score != addr[i][j - 1].score) {
        addr[i][j].status = j + 1;
      } else {
        addr[i][j].status = addr[i][j - 1].status;
      }
      all.push_back(addr[i][j]);
    }
  }
  sort(all.begin(), all.end(), greater<student>());
  for (int i = 0; i < (int) all.size(); i++) {
    if (i == 0) {
      all[i].rank = i + 1;
    } else
    if (all[i].score != all[i - 1].score) {
      all[i].rank = i + 1;
    } else {
      all[i].rank = all[i - 1].rank;
    }
  }
  cout << all.size() << '\n';
  for (int i = 0; i < (int) all.size(); i++) {
    cout << all[i].id << " " << all[i].rank << " " << all[i].addr << " " << all[i].status << '\n';
  }
  return 0;
}