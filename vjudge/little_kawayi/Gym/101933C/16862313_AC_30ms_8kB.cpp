#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[400];
    memset(a,0,sizeof a);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]=1;
    }
    int ans=0,cnt=0,sum=0;
    for(int i=1;i<365;i++)
    {
        sum+=cnt;
        if(a[i]==1)
        {
            cnt++;
        }
        if(sum+cnt>=20)
        {
            ans++;
            cnt=0;
            sum=0;
        }
    }
    if(a[365]==1)
        cnt++;
    if(cnt!=0)
        ans++;
    cout<<ans<<endl;
}
