/**
 *    author: Jingbo Su
 *    created: 28.05.2022 
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class BigInt {
 public:
  using Bint = vector<int>;

  BigInt() : mod(0) {};

  BigInt(Bint v, bool sign) : value(v), sign(sign), mod(0) {}

  BigInt(Bint v, bool sign, int mod) : value(v), sign(sign), mod(mod) {}

  template <typename U>
  BigInt(const U& x) {
    string s(to_string(x));
    sign = (s.front() == '-' ? 1 : 0);
    for (char& c : s) {
      if (c == '-') continue;
      assert(isdigit(c));
      value.push_back(c - '0');
    }
  }

  BigInt add(BigInt a, BigInt b) {
    Bint x = a.value;
    Bint y = b.value;
    bool& s1 = a.sign;
    bool& s2 = b.sign;
    if (s1 == 0 && s2 == 1) { s2 = 0; return sub(a, b); }
    if (s1 == 1 && s2 == 0) { s1 = 0; return sub(b, a); }
    bool sign = (s1 == 1 && s2 == 1 ? 1 : 0);
    int n = (int) x.size();
    int m = (int) y.size();
    if (n < m) return add(b, a);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    Bint ans;
    int cry = 0;
    for (int i = 0; i < n; i++) {
      cry += x[i];
      if (i < m) cry += y[i];
      ans.push_back(cry % 10);
      cry /= 10;
    }
    if (cry != 0) ans.push_back(cry);
    return BigInt(Bint(ans.rbegin(), ans.rend()), sign);
  }

  BigInt sub(BigInt& a, BigInt& b) {
    Bint x = a.value;
    Bint y = b.value;
    bool& s1 = a.sign;
    bool& s2 = b.sign;
    if (s1 == 0 && s2 == 1) { s2 = 0; return add(a, b); }
    if (s1 == 1 && s2 == 0) { s2 = 1; return add(a, b); }
    if (s1 == 1 && s2 == 1) { s2 = 0; return add(a, b); }
    bool sign = 0;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if (!cmp(x, y)) {
      sign = 1;
      swap(x, y);
    }
    int n = (int)x.size();
    int m = (int)y.size();
    Bint ans;
    for (int i = 0, neg = 0; i < n; i++) {
      neg = x[i] - neg;
      if (i < m) neg -= y[i];
      ans.push_back((neg + 10) % 10);
      if (neg < 0) neg = 1;
      else neg = 0;
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    return BigInt(Bint(ans.rbegin(), ans.rend()), sign);
  }

  BigInt mul(BigInt& a, BigInt& b) {
    Bint x = a.value;
    Bint y = b.value;
    bool sign = a.sign ^ b.sign;
    int n = (int) x.size();
    int m = (int) y.size();
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    Bint z(n + m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        z[i + j] += x[i] * y[j];
      }
    }
    for (int i = 0, cry = 0; i < n + m; i++) {
      cry += z[i];
      z[i] = cry % 10;
      cry /= 10;
    }
    while (z.size() > 1 && z.back() == 0) z.pop_back();
    return BigInt(Bint(z.rbegin(), z.rend()), sign);
  }

  template <typename T>
  BigInt div(BigInt& a, T& b) {
    Bint ans;
    Bint v = a.value;
    int n = (int) v.size();
    reverse(v.begin(), v.end());
    bool zero = false;
    int md = 0;
    for (int i = n - 1; i >= 0; i--) {
      md = md * 10 + v[i];
      int x = md / b;
      if (x || zero) {
        ans.push_back(x);
        zero = true;
      }
      md %= b;
    }
    if (ans.size() == 0) ans.push_back(0);
    return BigInt(Bint(ans.begin(), ans.end()), sign, md);
  }

  bool cmp(Bint x, Bint y) {
    if (x.size() != y.size()) return x.size() > y.size();
    for (int i = (int)x.size() - 1; i >= 0; i--) {
      if (x[i] != y[i]) {
        return x[i] > y[i];
      }
    }
    return true;
  }
  
  int mod;

  BigInt& operator+=(BigInt other) { return *this = add(*this, other); }
  BigInt& operator-=(BigInt other) { return *this = sub(*this, other); }

  template <typename U> BigInt& operator+=(U& other) { return *this += BigInt(other); }
  template <typename U> BigInt& operator-=(U& other) { return *this -= BigInt(other); }

  BigInt& operator++() { return *this += 1; }
  BigInt& operator--() { return *this += 1; }

  BigInt operator-() { sign = 1; return *this; }

  BigInt& operator*=(BigInt& other) { return *this = mul(*this, other); }
  template <typename U> BigInt& operator/=(U& other) { return *this = div(*this, other); }

  friend Bint& abs(BigInt& x) { return x.value; }

  friend bool operator==(BigInt& lhs, BigInt& rhs);

  friend bool operator<(BigInt& lhs, BigInt& rhs);

  friend BigInt max(BigInt& a, BigInt& b) {
    Bint x = a.value;
    Bint y = b.value;
    if (x.size() > y.size()) return x;
    if (x.size() < y.size()) return y;
    if (Bint(x.rbegin(), x.rend()) > Bint(y.rbegin(), y.rend())) return x;
    return y;
  }

  void read(const string& s);
  string write();

  template <typename U>
  friend U& operator>>(U& stream, BigInt& number);

  string to_string(const BigInt& number) {
    string res("");
    for (const auto& x : number.value) {
      res += to_string(x);
    }
    return res;
  }

 private:
  Bint value;
  bool sign;
};

bool operator==(BigInt& lhs, BigInt& rhs) { return (lhs.value == rhs.value && lhs.sign == rhs.sign); }
template <typename U> bool operator==(BigInt& lhs, U rhs) { return (lhs == BigInt(rhs) && lhs.sign == BigInt(rhs).sign); }
template <typename U> bool operator==(U lhs, BigInt& rhs) { return (BigInt(lhs) == rhs && BigInt(lhs).sign == rhs.sign); }

bool operator!=(BigInt& lhs, BigInt& rhs) { return !(lhs == rhs); }
template <typename U> bool operator!=(BigInt& lhs, U rhs) { return !(lhs == rhs); }
template <typename U> bool operator!=(U lhs, BigInt& rhs) { return !(lhs == rhs); }

bool operator<(BigInt& lhs, BigInt& rhs) {
  BigInt::Bint x = lhs.value;
  BigInt::Bint y = rhs.value;
  bool s1 = lhs.sign;
  bool s2 = rhs.sign;
  if (s1 == 0 && s2 == 0) return x < y;
  if (s1 == 0 && s2 == 1) return true;
  if (s1 == 1 && s2 == 0) return false;
  if (s1 == 1 && s2 == 1) return x > y;
  return {};
}
bool operator>=(BigInt lhs, BigInt rhs) { return !(lhs < rhs); }

BigInt operator+(BigInt lhs, BigInt rhs) { return lhs += rhs; }
template <typename U> BigInt operator+(BigInt& lhs, U rhs) { return lhs += rhs; }
template <typename U> BigInt operator+(U lhs, BigInt& rhs) { return lhs += rhs; }

BigInt operator-(BigInt lhs, BigInt rhs) { return lhs -= rhs; }
template <typename U> BigInt operator-(BigInt lhs, U rhs) { return lhs -= rhs; }
template <typename U> BigInt operator-(U lhs, BigInt rhs) { return lhs -= rhs; }

BigInt operator*(BigInt lhs, BigInt rhs) { return lhs *= rhs; }
template <typename U> BigInt operator*(BigInt lhs, U rhs) { return lhs *= rhs; }
template <typename U> BigInt operator*(U lhs, BigInt rhs) { return lhs *= rhs; }

template <typename U> BigInt operator/(BigInt lhs, U rhs) { return lhs /= rhs; }

void BigInt::read(const string& s) {
  sign = 0;
  value.clear();
  if (s.front() == '-') sign = 1;
  for (char c : s) {
    if (c == '-') continue;
    assert(isdigit(c));
    value.push_back(c - '0');
  }
}

string BigInt::write() {
  string ans = (sign == 1 ? "-" : "");
  for (int& out : value) {
    ans += out + '0';
  }
  return ans;
}

// U == std::istream? but done this way because of fastinput
template <typename U>
U& operator>>(U& stream, BigInt& number) {
  string s;
  stream >> s;
  number.read(s);
  return stream;
}

template <typename U>
U& operator<<(U& stream, BigInt& number) {
  stream << number.write();
  return stream;
}

template <typename T, typename U>
inline T power(const T& a, const T& b, const U& mod) {
  assert(b >= 0);
  T x = a, p = b, ans = 1;
  while (p > 0) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  BigInt x, y;
  cin >> x >> y;
  int z;
  cin >> z;
  cout << x << y << z << '\n';
  BigInt a = x + y;
  BigInt b = x - y;
  BigInt c = x * y;
  BigInt d = x / z;
  cout << a << " " << b << " " << c << " " << d << '\n';
  return 0;
}