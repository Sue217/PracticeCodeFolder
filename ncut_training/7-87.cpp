/**
 *    author: subobo
 *    created: 19.01.2022 09:46:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> mot(n);
  for (auto& in : mot) {
    cin >> in;
  }
  sort(mot.begin(), mot.end());
  int md = n / 2;
  long long diff = 0;
  for (int i = md; i < n; i++) {
    diff += mot[i];
  }
  for (int i = 0; i < md; i++) {
    diff -= mot[i];
  }
  if (n % 2) {
    md += 1;
  }
  cout << "Outgoing #: " << md << '\n';
  cout << "Introverted #: " << n - md << '\n';
  cout << "Diff = " << diff << '\n';
  return 0;
}