#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int sx, hh, ww;
    cin >> sx >> hh >> ww;
    if (sx == 0) {
      if (hh < 129) {
        cout << "duo chi yu! ";
      } else
      if (hh > 129) {
        cout << "ni li hai! ";
      } else {
        cout << "wan mei! ";
      }
      if (ww < 25) {
        cout << "duo chi rou!";
      } else
      if (ww > 25) {
        cout << "shao chi rou!";
      } else {
        cout << "wan mei!";
      }
    } else {
      if (hh < 130) {
        cout << "duo chi yu! ";
      } else
      if (hh > 130) {
        cout << "ni li hai! ";
      } else {
        cout << "wan mei! ";
      }
      if (ww < 27) {
        cout << "duo chi rou!";
      } else
      if (ww > 27) {
        cout << "shao chi rou!";
      } else {
        cout << "wan mei!";
      }
    }
    cout << '\n';
  }
  return 0;
}