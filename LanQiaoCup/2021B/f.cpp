/**
 *    author: subobo
 *    created: 08.04.2022 14:04:11
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
  long long time;
  cin >> time;
  time /= 1000;
  time %= 86400;
  string second = to_string(time % 60); time /= 60;
  string minute = to_string(time % 60); time /= 60;
  string hour = to_string(time);
  cout << (hour.size() == 1 ? "0" + hour : hour) << ":"
       << (minute.size() == 1 ? "0" + minute : minute) << ":"
       << (second.size() == 1 ? "0" + second : second) << '\n';
  return 0;
}