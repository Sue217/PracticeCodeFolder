/**
 *    author:  BOBLT
 *    created: 4.12.2021
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int mod = 998244353;
    int n; cin >> n;
    map<ll, int> dp;
    dp[0] = 1;
    ll res = 0, cur = 1;
    ll perSum = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        perSum += a;
        res = cur;
        if (perSum == 0) {
            ++res;
        }
        res %= mod;
        cur = (cur - dp[perSum] + mod) % mod;
        dp[perSum] = res;
        cur += dp[perSum];
        cur %= mod;
    }
    if (perSum == 0) {
        --res;
    }
    cout << res << '\n';
    return 0;
}
