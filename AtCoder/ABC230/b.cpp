/**
 *    author:  BOBLT
 *    created: 3.12.2021
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = (int)s.size();
    if (n == 1) {
        cout << "Yes" << '\n';
        return 0;
    }
    if (n == 2) {
        if (s == "oo") {
            cout << "No" << '\n';
            return 0;
        }
        cout << "Yes" << '\n';
        return 0;
    }
    int pos = 0;
    if (s[0] == 'x') {
        pos = 1;
        if (s[1] == 'x') {
            pos = 2;
            if (s[2] == 'x') {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    int i = pos;
    for (i = pos; i + 3 <= n; i += 3) {
        if (s.substr(i, 3) != "oxx") {
            cout << "No" << '\n';
            return 0;
        }
    }
    if (i == n - 1) {
        if (s[i] == 'o') {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return 0;
    }
    else if (i == n - 2) {
        if (s[i] == 'o' and s[i + 1] == 'x') {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return 0;
    }
    cout << "Yes" << '\n';
    return 0;
}
