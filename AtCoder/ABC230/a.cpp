/**
 *    author:  BOBLT
 *    created: 3.12.2021
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    if (n < 10) {
        cout << "AGC00" << n << '\n';
    }
    if (n < 42 and n >= 10) {
        cout << "AGC0" << n << '\n';
    }
    if (n >= 42) {
        cout << "AGC0" << n + 1 << '\n';
    }
    return 0;
}
