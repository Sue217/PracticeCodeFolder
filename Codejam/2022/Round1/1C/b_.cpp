#include <bits/stdc++.h>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i, a, b) for (register int i = a, i##end = b; i <= i##end; ++i)
#define UF(i, a, b) for (register int i = a, i##end = b; i >= i##end; --i)
#define re register
#define ri re int
#define il inline
#define pii pair<int, int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x, 0, sizeof(x))
#define mem0x3f(x) memset(x, 0x3f, sizeof(x))
using namespace std;
const double Pi = acos(-1);
namespace fastIO {
template <class T>
inline void read(T& x) {
  x = 0;
  bool fu = 0;
  char ch = 0;
  while (ch > '9' || ch < '0') {
    ch = getchar();
    if (ch == '-') fu = 1;
  }
  while (ch <= '9' && ch >= '0') x = (x * 10 - 48 + ch), ch = getchar();
  if (fu) x = -x;
}
inline int read() {
  int x = 0;
  bool fu = 0;
  char ch = 0;
  while (ch > '9' || ch < '0') {
    ch = getchar();
    if (ch == '-') fu = 1;
  }
  while (ch <= '9' && ch >= '0') x = (x * 10 - 48 + ch), ch = getchar();
  return fu ? -x : x;
}
template <class T, class... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
char _n_u_m_[40];
template <class T>
inline void write(T x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  T tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  register int cnt = 0;
  while (tmp > 0) {
    _n_u_m_[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(_n_u_m_[--cnt]);
}
template <class T>
inline void write(T x, char ch) {
  write(x);
  putchar(ch);
}
}  // namespace fastIO
using namespace fastIO;
int n;
vector<int> a;
int main() {
  F(sadf, 1, read()) {
    cin >> n;
    a.clear();
    int K = read();
    ll sum = 0, ff = 0;
    F(i, 1, n)
    a.push_back(read()), sum += a.back(), ff += 1ll * a.back() * a.back();
    printf("Case #%d: ", sadf);
    if (K > 1) {
      a.push_back(-sum + 1);
      write(a.back(), ' ');
      sum += a.back(), ff += 1ll * a.back() * a.back();
    }
    ll ss = sum * sum;
    ll d = ff - ss;
    d /= 2;
    if (K == 1) {
      if (sum == 0) {
        if (d == 0)
          puts("0");
        else
          puts("IMPOSSIBLE");
      } else {
        if (d % sum == 0) {
          write(d / sum, '\n');
        } else
          puts("IMPOSSIBLE");
      }

    } else {
      write(d, '\n');
    }
  }
  return 0;
}
