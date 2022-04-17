#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define FastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int N = 1e5 + 5, M = 1e2 + 5;
const char cr = 10, sp = 32;
const int inf = 0x3f3f3f3f;

int main() {
    ll t, n, a, b;
    FastIO;
    cin >> t;
    while ( t-- ) {
        cin >> n >> a >> b;
        if (a == 0) {
          cout << 1 << '\n';
        } else {
          cout << n * a / b + (bool) (n * a % b / a) << cr;
        }
    }
    return 0;
}