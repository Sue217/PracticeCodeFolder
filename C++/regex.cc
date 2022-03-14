/**
 *    author: subobo
 *    created: 14.03.2022
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
  string s;
  getline(cin, s);
  // [  cat   scattered.  -cat- , dogcatdog]
  s = regex_replace(s, regex(" +"), " ");
  s = regex_replace(s, regex("^ | $"), "");
  s = regex_replace(s, regex(" (\\W)"), "$1");
  string t(s);
  s = regex_replace(s, regex("\\bcat\\b"), "CAT");
  cout << s << endl;
  // [CAT scattered.-CAT-, dogcatdog]
  t = regex_replace(t, regex("\\Bcat\\B"), "CAT");
  cout << t << endl;
  // [cat sCATtered.-cat-, dogCATdog]
  return 0;
}