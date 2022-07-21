#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const char sp = 32, cr = 10;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 5, M = 1e5;

int a[N], n;
int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0;i <= n;++i) {
            cin >> a[i];
        }
        if (a[0] > 0 || a[1] >= 2) cout << "Alice\n";
        else {
            int sum = 0;
            bool f = false;
            for (int i = 1;i <= n;++i) {
                if (a[i] >= 2 && i <= sum + 1) {
                    f = true;break;
                }
                sum += a[i];
            }
            if (f) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }



    return 0;
}