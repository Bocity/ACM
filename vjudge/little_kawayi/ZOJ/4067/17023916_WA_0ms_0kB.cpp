#include<bits/stdc++.h>
using namespace std;
const long long  maxn=1e5+10;
long long  p[maxn];
int  main()
{
    long long  t;
    cin>>t;
    while(t--)
    {
        long long  n,m;
        cin>>n>>m;
        long long minx=20000000000;
        for(int i=0;i<n;i++)
            cin>>p[i],minx=min(minx,p[i]);
        if(n==m)
        {
            cout<<"Richman"<<endl;
        }else
        if(m==0)
        {
            cout<<minx-1<<endl;
        }else
        if(p[m]==0)
        {
            cout<<"Impossible"<<endl;
        }else

        {
            long long  sum=0;
            for(int  i=0;i<m;i++)
                sum+=p[i];
            sum+=p[m]-1;
            cout<<sum<<endl;
        }
    }
}
