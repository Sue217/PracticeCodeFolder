/**
 *    author: subobo
 *    created: 19.02.2022 20:47:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  array<int, 8> dx{-2, -2, -1, -1, 1, 1, 2, 2}, dy{-1, 1, -2, 2, -2, 2, -1, 1};
  for (int i = 0; i < 8; i++) {
    int xx = x1 + dx[i], yy = y1 + dy[i];
    // cerr << xx << ", " << yy << "; ";
    for (int j = 0; j < 8; j++) {
      int px = x2 + dx[j], py = y2 + dy[j];
      // cerr << px << ", " << py << '\n';
      if (xx == px && yy == py) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}