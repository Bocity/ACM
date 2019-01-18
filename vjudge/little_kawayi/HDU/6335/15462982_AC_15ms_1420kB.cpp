#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        long long a[n];
        for(long long i=0; i<n; i++)
        {
            long long x,y;
            cin>>x>>y;
            a[i]=x+y;
        }
        sort(a,a+n);
        long long ans=1;
        for(long long i=0;; i++)
        {
            if(ans*a[i]<=m)
            {
                ans=ans*a[i];
            }
            else
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }

}
