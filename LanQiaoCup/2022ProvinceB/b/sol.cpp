#include <bits/stdc++.h>

using namespace std;

int main() {
  string year = "2022";
  string month = "";
  string day = "";
  auto get = [&](int m) {
    switch (m) {
      case 1: return 31;
      case 2: return 28;
      case 3: return 31;
      case 4: return 30;
      case 5: return 31;
      case 6: return 30;
      case 7: return 31;
      case 8: return 31;
      case 9: return 30;
      case 10: return 31;
      case 11: return 30;
      case 12: return 31;
    }
    return -1;
  };
  auto find = [&](string y) {
    for (int i = 0; i < 8; i++) {
      for (int j = i + 1; j < 8; j++) {
        for (int k = j + 1; k < 8; k++) {
          if (y[i] + 1 == y[j] && y[j] + 1 == y[k] && y[i] + 2 == y[k]) { 
            return true;
          }
        }
      }
    }
    return false;
  };
  int ans = 0;
  for (int m = 1; m <= 9; m++) {
    month = "0" + to_string(m);
    for (int d = 1; d <= 9; d++) {
      day = "0" + to_string(d);
      year += month;
      year += day;
      if (find(year)) {
        ans += 1;
      }
    }
    for (int d = 10; d <= get(m); d++) {
      day = to_string(d);
      year += month;
      year += day;
      if (find(year)) {
        ans += 1;
      }
    }
  }
  for (int m = 10; m <= 12; m++) {
    month = to_string(m);
    for (int d = 1; d <= 9; d++) {
      day = "0" + to_string(d);
      year += month;
      year += day;
      if (find(year)) {
        ans += 1;
      }
    }
    for (int d = 10; d <= get(m); d++) {
      day = to_string(d);
      year += month;
      year += day;
      if (find(year)) {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}