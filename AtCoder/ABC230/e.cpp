/**
 *    author:  BOBLT
 *    created: 3.12.2021
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll res = 0, l = 1;
    while (l <= n) {
        ll t = n / l;
        ll r = n / t;
        cerr << l << " " << r << '\n';
        res += (r - l + 1) * t;
        l = r + 1;
    }
    cout << res << '\n';
    return 0;
}
