/*
ID: sujingb1
TASK: namenum
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream ifstr ("dict.txt");
  string num;
  fin >> num;
  string name;
  map<char, int> mp;
  char ch = 'A';
  for (int i = 2; i <= 9; i++) {
    for (int j = 0; j < 3; j++) {
      if (ch + j == 'Q') {
        ch += 1;
      }
      mp[ch + j] = i;
    }
    ch += 3;
  }
  bool ok = true;
  set<string> sst;
  while (ifstr >> name) {
    string ans = "";
    for (char c : name) {
      ans += mp[c] + '0';
    }
    if (ans == num) {
      ok = false;
      sst.insert(name);
    }
  }
  if (ok) {
    fout << "NONE\n";
  } else {
    for (auto it : sst) {
      fout << it << '\n';
    }
  }
  return 0;
}