#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[100010];
int main()
{
    a[1]=1;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    for(long long
        i=5;i<100010;i++)
    {
        a[i]=a[i-1]*(i-2)%mod+a[i-2]*(i-1)%mod;
        if(i&1)
            a[i]++;
        else
            a[i]--;
        a[i]+=mod;
        a[i]%=mod;
    }
        int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<a[n]<<endl;
    }
}
