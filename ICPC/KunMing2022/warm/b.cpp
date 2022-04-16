#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll p){
	ll ans=1ll;
	while(p){
		if(p&1)ans=ans*a;
		a=a*a;
		p>>=1;
	}
	return ans;
}

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	int n=s.size()-1;
	ll k=0,m=0;
	for(int i=0;i<=n;++i){
		ll t=s[i]-'0';
		if(t==0)continue;
		int d=n-i;
		ll ans=qpow(2,d);
		ll c=qpow(3,i);
		ll dd=qpow(2,i);
		k+=(t*c*ans);
	}
	m=qpow(2,n);
	if(k%m == 0)cout<<(k/m)<<endl;
	else {
		ll g=gcd(k,m);
		k/=g;
		m/=g;
		ll a=k/m;
		k%=m;
		cout<<a<<' '<<k<<'/'<<m<<endl;
	}
	return 0;
}