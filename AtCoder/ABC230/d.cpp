/**
 *    author:  BOBLT
 *    created: 4.12.2021
**/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d; cin >> n >> d;
    vector<pii> vp;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        vp.emplace_back(make_pair(l, r));
    }
    sort(vp.begin(), vp.end(), [](pii pa, pii pb) {return pa.second < pb.second;});
    int res = 0, ed = -(int)2e9;
    for (auto i : vp) {
        if (i.first > ed) {
            ++res;
            ed = i.second + d - 1;
        }
    }
    cout << res << '\n';
    return 0;
}
