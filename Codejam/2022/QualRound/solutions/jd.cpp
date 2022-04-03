#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> f(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> f[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int p;
        std::cin >> p;
        adj[p].push_back(i);
    }
    
    i64 ans = 0;
    
    auto dfs = [&](auto self, int u) -> i64 {
        if (adj[u].empty()) {
            return f[u];
        }
        int x = 0;
        for (auto v : adj[u]) {
            int y = self(self, v);
            if (x == 0 || x > y) {
                std::swap(x, y);
            }
            ans += y;
        }
        return std::max(x, f[u]);
    };
    ans += dfs(dfs, 0);
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}