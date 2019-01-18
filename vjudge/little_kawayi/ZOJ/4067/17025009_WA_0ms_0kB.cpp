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
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            if(p[i]==0)
            {

                cnt++;
            }else
            {
                 minx=min(minx,p[i]);
            }
        }
        if(n==m)
        {
            cout<<"Richman"<<endl;
        }else
        if(m<cnt)
            cout<<"Impossible"<<endl;
        else
        {
            long long  sum=0;
            m=m-cnt;
            if(m==0)
            {
                cout<<minx-1<<endl;
                continue;
            }
            for(int i=0;m!=-1;i++)
            {
                if(p[i]!=0)
                    sum+=p[i],m--;
            }
            cout<<sum-1<<endl;
        }
    }
}
