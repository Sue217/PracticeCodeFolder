#include <iostream>
#include <set>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 15, M = 1e2 + 5;
const char cr = 10, sp = 32;
const int inf = 0x3f3f3f3f;

set<char> m[N];
string str;
bool vis[N];
int n;

bool dfs(int k) {
  if (k >= str.length()) return true;
  bool f = false;
  for (int i = 0; i < n; ++i) {
    if (m[i].count(str[k]) && !vis[i]) {
      vis[i] = true;
      f |= dfs(k + 1);
      vis[i] = false;
    }
  }
  return f;
}

int main() {
  cin >> n;
  for (int i = 0; i < 4; ++i) {
    cin >> str;
      for (auto ch : str) m[i].insert(ch);
  }
  for (int i = 0; i < n; ++i) {
    memset(vis, 0, sizeof(vis));
    cin >> str;
    int len = str.length();
    if (dfs(0)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}