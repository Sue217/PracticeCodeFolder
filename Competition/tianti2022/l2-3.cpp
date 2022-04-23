#include <bits/stdc++.h>

using namespace std;

const int N = 86410;

vector<int> fenw(N), p(N);

inline void modify(int x, int y) {
	int z = x;
	while (x < N) {
		fenw[x] += y;
		p[x] += x * 
		x |= (x + 1);
	}
}

inline int get(int x) {
	int y = 0, z = 0;
	while (x > 0) {
		y += fenw[x];
		x = (x & (x + 1)) - 1;
	}
	return y;
}

int main() {
	int tt;
	cin >> tt;
	++tt;
	while (tt--) {
		string xs; 
		getline(cin, xs);
		cout << xs << '\n';
		string ss("");
		ss += xs[0]; ss += xs[1];
		int h = stoi(ss);
		ss = ""; ss += xs[3]; ss += xs[4];
		int m = stoi(ss);
		ss = ""; ss += xs[6]; ss += xs[7];
		int s = stoi(ss);
		
		ss = ""; ss += xs[11]; ss += xs[12];
		int H = stoi(ss);
		ss = ""; ss += xs[14]; ss += xs[15];
		int M = stoi(ss);
		ss = ""; ss += xs[17]; ss += xs[18];
		int S = stoi(ss);
		
		int from = h * 3600 + m * 60 + s;
		int to = H * 3600 + M * 60 + S;
	}
	return 0;
}