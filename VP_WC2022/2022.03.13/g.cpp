/**
 *    author: subobo
 *    created: 13.03.2022 18:52:18
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
  int tt;
  cin >> tt;
  while (tt--) {
    int sex, h, w;
    cin >> sex >> h >> w;
    if (sex == 0) {
      if (h < 129) {
        cout << "duo chi yu!" << " ";
      } else
      if (h > 129) {
        cout << "ni li hai!" << " ";
      } else {
        cout << "wan mei!" << " ";
      }
      if (w < 25) {
        cout << "duo chi rou!" << '\n';
      } else
      if (w > 25) {
        cout << "shao chi rou!" << '\n';
      } else {
        cout << "wan mei!" << '\n';
      }
    } else
    if (sex == 1) {
      if (h < 130) {
        cout << "duo chi yu!" << " ";
      } else
      if (h > 130) {
        cout << "ni li hai!" << " ";
      } else {
        cout << "wan mei!" << " ";
      }
      if (w < 27) {
        cout << "duo chi rou!" << '\n';
      } else
      if (w > 27) {
        cout << "shao chi rou!" << '\n';
      } else {
        cout << "wan mei!" << '\n';
      }
    }
  }
  return 0;
}