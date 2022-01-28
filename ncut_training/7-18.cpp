/**
 *    author: subobo
 *    created: 28.01.2022 22:09:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n);
  for (int& in : seq) {
    cin >> in;
  }
  if (n == 1) {
    cout << seq.back() << '\n';
    return 0;
  }
  vector<int> sum;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum.emplace_back(seq[i] + seq[j]);
    }
  }
  sort(sum.begin(), sum.end());
  for (int i = 0; i < (int) sum.size() - 1; i++) {
    cout << sum[i] << " ";
  }
  cout << sum.back() << '\n';
  return 0;
}