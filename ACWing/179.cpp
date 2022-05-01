/**
 *    author: subobo
 *    created: 29.04.2022 07:54:35
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string xs;
  getline(cin, xs);
  string start("");
  for (char& c : xs) {
    if (c == ' ') continue;
    start += c;
  }
  static constexpr int N = 9;
  int rvs = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (start[i] != 'x' && start[j] != 'x' && start[j] < start[i]) {
        rvs += 1;
      }
    }
  }
  if (rvs % 2 == 1) {
    cout << "unsolvable" << '\n';
    return 0;
  }
  auto f = [&](string& status) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (status[i] != 'x') {
        int v = status[i] - '1';
        ans += (int) (abs(i / 3 - v / 3) + abs(i % 3 - v % 3));
      }
    }
    return ans;
  };
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> s;
  map<string, int> dist;
  map<string, pair<string, char>> prev;
  string finish = "12345678x";
  array<int, 4> dx{-1, 0, 1, 0};
  array<int, 4> dy{0, 1, 0, -1};
  array<char, 4> ops{'u', 'r', 'd', 'l'};
  s.emplace(f(start), start);
  dist[start] = 0;
  while (!s.empty()) {
    auto t = s.top();
    s.pop();
    if (t.second == finish) break;
    string now(t.second);
    string old(t.second);
    int zero = 0;
    for (int i = 0; i < N; i++) {
      if (now[i] == 'x') {
        zero = i;
        break;
      }
    }
    int x = zero / 3;
    int y = zero % 3;
    int dd = dist[now];
    for (int i = 0; i < 4; i++) {
      now = old;
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (0 <= xx && xx < 3 && 0 <= yy && yy < 3) {
        swap(now[x * 3 + y], now[xx * 3 + yy]);
        if (dist.count(now) == 0 || dd + 1 < dist[now]) {
          dist[now] = dd + 1;
          prev[now] = make_pair(old, ops[i]);
          s.emplace(dist[now] + f(now), now);
        }
      }
    }
  }
  string ans = "";
  while (finish != start) {
    debug(finish, prev[finish].first);
    ans += prev[finish].second;
    finish = prev[finish].first;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  cerr << "time: " << clock() << " ms" << '\n';
  return 0;
}