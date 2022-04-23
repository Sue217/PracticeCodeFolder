#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	assert(n > 0);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<int> stk;
	int prev = a[0];
	vector<int> ans(1, prev);
	for (int i = 1; i < (int) a.size(); i++) {
		if (a[i] > prev) {
			if ((int) stk.size() < m) {
			  stk.push(a[i]);
			} else {
				for (int j = 0; j < (int) ans.size(); j++) {
					cout << ans[j] << " \n"[j == (int) ans.size() - 1];
				}
				int id = i - 1;
				for (int j = 0; j < m; j++) {
					a[id] = stk.top();
					stk.pop();
					--id;
				}
			}
		} else {
			if ((int) ans.size() < k) {
				ans.push_back(a[i]);
			}
			if ((int) ans.size() == k) {
				for (int j = 0; j < k; j++) {
					cout << ans[j] << " \n"[j == k - 1];
				}
				ans.clear();
			}
		}
	}
	ans.clear();
	vector<int> que;
	if (!stk.empty()) {
		prev = stk.top();
		stk.pop();
		ans.push_back(prev);
	  while (!stk.empty()) {
	  	que.push_back(stk.top());
	  	stk.pop();
	  }
	  for (int b = 0; b < (int) que.size(); b++) {
	  	if (que[b] > prev) {
	  		if ((int) ans.size() == k) {
	  			for (int i = 0; i < k; i++) {
	  				cout << ans[i] << " \n"[i == k - 1];
	  			}
	  			ans.clear();
	  		}
	  		ans.push_back(que[b]);
	  	} else {
	  		for (int i = 0; i < (int) ans.size(); i++) {
	  			cout << ans[i] << " \n"[i == (int) ans.size() - 1];
	  		}
	  	}
	  }
	}
	return 0;
}