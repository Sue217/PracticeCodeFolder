#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define int ll

const int N = 1e5 + 5, M = 1e5 + 5;
const char cr = 10, sp = 32;
const int inf = 0x3f3f3f3f;

signed main() {
  FastIO;
  int tt;
  cin >> tt;
  while (tt--) {
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
    int t=i;
    for(int i=0;t%2==0&&i<m;++i) t/=2;
    sum+=t;
    }
    cout<<sum<<endl;
  }

    return 0;
}