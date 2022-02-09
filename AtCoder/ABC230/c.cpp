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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    for (ll i = p; i <= q; ++i) {
        for (ll j = r; j <= s; ++j) {
            bool ok = true;
            if (i - a == j - b) {
                ok = false;
            }
            if (i - a == b - j) {
                ok = false;
            }
            if (ok) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << '\n';
    }
    return 0;
}
