/**
 *    author: Jingbo Su
 *    created: 20.01.2022 10:09:57
 *    title: Regular expression
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string pattern("[^c]ei");
  pattern = "[[:alpha:]]+" + pattern + "[[:alpha:]]+";
  regex r(pattern);
  smatch result;
  string s = "receipt freind theif receive";
  if (regex_search(s, result, r)) {
    cout << result.str() << '\n';
  }
  return 0;
}
