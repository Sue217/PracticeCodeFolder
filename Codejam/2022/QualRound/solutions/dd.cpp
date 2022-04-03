#include <bits/stdc++.h>

using namespace std;

int test, n, a[100001];
vector<int> edge[100001];
long long f[100001], s[100001], v[100001];
bool b[100001];

inline void dfs(int x) {
	b[x] = true;
	int idx = 0;
	long long w = 1LL << 60LL;
	for (auto y : edge[x]) {
		dfs(y);
		if (s[y] < w)
			w = s[y], idx = y;
	}
	f[x] = 0;
	for (auto y : edge[x]) {
		if (y != idx)
			f[x] += f[y];
	}
	s[x] = max(1LL * a[x], s[idx]);
	v[x] = f[x] + v[idx];
	f[x] += s[x] + v[idx];
}

int main() {
	scanf("%d", &test);
	for (int uu = 1; uu <= test; uu++) {
		printf("Case #%d: ", uu);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			edge[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (x)
				edge[x].push_back(i);
		}
		memset(b, false, sizeof(b));
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			if (!b[i]) {
				dfs(i);
				ans += f[i];
			}
		printf("%lld\n", ans);
	}

}