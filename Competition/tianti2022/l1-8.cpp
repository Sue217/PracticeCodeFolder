#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  vector<tuple<int, int, int>> a;
  for (int i = 0; i < n; i++) {
  	int t, p;
  	cin >> t >> p;
  	if (t < 175) continue;
  	a.emplace_back(t, p, 0);
  }
  sort(a.begin(), a.end(), [&](auto x, auto y) {
	  if (get<0>(x) == get<0>(y)) {
	  	return get<1>(x) < get<1>(y);
	  }
	  return get<0>(x) > get<0>(y);
	});
	queue<tuple<int, int, int>> que;
	for (auto it : a) {
		que.emplace(it);
	}
  int bg = 0;
  int mx = (int) 1e9;
  int ans = 0;
  while (!que.empty()) {
  	int t = get<0>(que.front());
  	int p = get<1>(que.front());
  	int m = get<2>(que.front());
  	que.pop();
  	if (m == bg) {
  		if (t < mx) {
  			ans += 1;
  		} else {
  			if (t == mx) {
  				if (p >= s) {
  				  ans += 1;
  				} else {
  					que.emplace(t, p, m + 1);
  				}
  			} else {
  				que.emplace(t, p, m + 1);
  			}
  		}
  	} else {
  		k -= 1;
  		bg = m;
  		if (k == 0) break;
  		ans += 1;
  	}
  	mx = t;
  }
  cout << ans;
	return 0;
}