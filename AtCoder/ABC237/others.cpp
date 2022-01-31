#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[1001][11][12][13];

int main(void){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll N,M;
  cin>>N>>M;
  
  dp[0][M][M+1][M+2]=1;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<=M;j++){
      for(ll k=j+1;k<=M+1;k++){
        for(ll l=k+1;l<=M+2;l++){
          for(ll x=0;x<M;x++){
            if(x<=j)     dp[i+1][x][k][l]+=dp[i][j][k][l];
            else if(x<=k)dp[i+1][j][x][l]+=dp[i][j][k][l];
            else if(x<=l)dp[i+1][j][k][x]+=dp[i][j][k][l];
          }
        }
      }
    }
  }
  
  ll ans=0;
  for(ll j=0;j<M;j++)
    for(ll k=j+1;k<M;k++)
      for(ll l=k+1;l<M;l++)
        ans+=dp[N][j][k][l];
  cout << ans << '\n';
}
