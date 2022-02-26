  /**
   *    author: subobo
   *    created: 25.02.2022 23:38:16
  **/
  #include <bits/stdc++.h>

  using namespace std;

  int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& in : a) {
      cin >> in;
    }
    sort(a.begin(), a.end());
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] % a[j] == 0) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
  }