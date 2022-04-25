#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t INF64 = int64_t(2e18) + 5;

void run_case(int test_case) {
    int N, P;
    cin >> N >> P;
    map<int, int64_t> dp;
    dp[0] = 0;

    for (int c = 0; c < N; c++) {
        vector<int> X(P);

        for (auto &x : X)
            cin >> x;

        sort(X.begin(), X.end());
        map<int, int64_t> ndp;
        ndp[X.front()] = ndp[X.back()] = INF64;

        for (auto &pr : dp) {
            ndp[X.back()] = min(ndp[X.back()], pr.second + abs(pr.first - X.front()) + (X.back() - X.front()));
            ndp[X.front()] = min(ndp[X.front()], pr.second + abs(pr.first - X.back()) + (X.back() - X.front()));
        }

        dp = ndp;
    }

    int64_t ans = INF64;

    for (auto &pr : dp)
        ans = min(ans, pr.second);

    cout << "Case #" << test_case << ": ";
    cout << ans << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
