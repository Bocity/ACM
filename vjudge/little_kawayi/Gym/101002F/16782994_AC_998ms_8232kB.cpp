#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e4+10;
long long dp[105][maxn];
const long long mod =1e9+7;
int main()
{
    long long m,x,y;
    cin>>m>>x>>y;
    memset(dp,0,sizeof dp);
    for(long long i=0;i<=y;i++)
    {
        dp[1][i]=1;
    }
    for(long long i=2;i<=x;i++)
    {
        for(long long j =  0;j<=m;j++)
        {
            long long ans=0;
            for(long long k=0;k<=y&&k<=j;k++)
            {
                ans=(dp[i-1][j-k]+ans) ;
                if(ans>=1e18)
                    ans%=mod;
            }

            dp[i][j]=ans;
        }
    }
//    for(long long i=1;i<=x;i++)
//    {
//        for(long long j=0;j<=m;j++)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    long long ans=0;
    for(long long i=0;i<=m;i++)
        ans=ans+dp[x][i]%mod;
    long long hh=min(m/x,y);
    cout<<(ans-(hh+1)+mod)%mod<<endl;

}
