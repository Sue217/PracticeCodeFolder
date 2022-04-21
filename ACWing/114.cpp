#include <bits/stdc++.h>

using namespace std;

vector<int> mult(vector<int>& a, int b) {
  vector<int> res;
  int t = 0;
  for (auto &i : a) {
    t += i * b;
    res.push_back(t % 10);
    t /= 10;
  }
  while (t) {
    res.push_back(t % 10);
    t /= 10;
  }
  return res;
}

vector<int> div(vector<int>& a, int b) {
  vector<int> res;
  bool isZero = false;
  for (int i = (int)a.size() - 1, t = 0; ~i; --i) {
    t = t * 10 + a.at(i);
    int x = t / b;
    if (x || isZero) {
      res.push_back(x);
      isZero = true;
    }
    t %= b;
  }
  return vector<int>(res.rbegin(), res.rend());
}

vector<int> Max(vector<int>& a, vector<int>&& b) {
  if (a.size() > b.size()) return a;
  if (a.size() < b.size()) return b;
  if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;
  return b;
}

int main() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  for (int i = 0; i < n; ++i) {
    int aa, bb;
    cin >> aa >> bb;
    s.emplace(aa * bb, bb);
  }
  vector<int> sum(1, a); // vector<int> sum(1, 1); sum = mult(sum, a);
  vector<int> res(1, 0);
  while (!s.empty()) {
    auto t = s.top(); s.pop();
    int l = t.first, r = t.second;
    res = Max(res, div(sum, r));
    sum = mult(sum, l / r);
  }

    // vector<pii> p;
    // for (int i = 0; i <= n; ++i) {
    //     int x, y;
    //     cin >> x >> y;
    //     p.emplace_back(make_pair(x * y, x));
    // }
    // sort(p.begin() + 1, p.end());
    // vector<int> sum(1, 1);
    // vector<int> res(1, 0);
    // for (int i = 0; i <= n; ++i) {
    //     if (i) {
    //         res = Max(res, div(sum, p.at(i).first / p.at(i).second));
    //     }
    //     sum = mult(sum, p.at(i).second);
    // }
    
  for_each(res.rbegin(), res.rend(), [&](const int& n) {cout << n;});

  return 0;
}