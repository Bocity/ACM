#include<bits/stdc++.h>
using namespace std;
const long long  maxn=1e5+10;
long long  p[maxn];
long long minx[maxn];
int  main()
{
    long long  t;
    cin>>t;
    while(t--)
    {
        long long  n,m;
        cin>>n>>m;
        long long nn=n;
        int cnt=0;
        for(int i=0;i<nn;i++)
        {
            cin>>p[i];
            if(p[i]==0)
            {
                cnt++;
                i--;
                nn--;
            }
        }
        minx[nn-1]=p[nn-1];
        for(int i=nn-2;i>=0;i--)
        {
            minx[i]=min(minx[i+1],p[i]);
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
                cout<<minx[0]-1<<endl;
                continue;
            }
            for( int i=0;i<m;i++)
            {
                sum+=p[i];
            }
            sum+=minx[m];
            cout<<sum-1<<endl;
        }
    }
}
