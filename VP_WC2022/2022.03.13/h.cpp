/**
 *    author: subobo
 *    created: 13.03.2022 19:00:12
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  int tt;
  cin >> tt;
  getchar();
  while (tt--) {
    string q;
    getline(cin, q);
    cout << q << endl;
    for (char& c : q) {
      if (isupper(c) && c != 'I') {
        c = tolower(c);
      }
    }
    q = regex_replace(q, regex(" +"), " ");
    q = regex_replace(q, regex("^ | $"), "");
    q = regex_replace(q, regex(" (\\W)"), "$1");
    q = regex_replace(q, regex("\\?"), "!");
    q = regex_replace(q, regex("\\bcan you\\b"), "S");
    q = regex_replace(q, regex("\\bcould you\\b"), "D");
    q = regex_replace(q, regex("\\b(I|me)\\b"), "A");
    q = regex_replace(q, regex("S"), "I can");
    q = regex_replace(q, regex("D"), "I could");
    q = regex_replace(q, regex("A"), "you");
    cout << "AI: " << q << endl;
  }
  return 0;
}