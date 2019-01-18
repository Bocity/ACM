#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 10000000 + 5;
long long n, m,k,p,xx,r,mod;
long long a[MAXN];
deque<long long> q;
inline long long read()
{
    long long x=0, f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch>='0' && ch<='9')
        x=(x<<3)+(x<<1)+ch-48, ch=getchar();
    return x * f;
}

int main()
{
    long long t;
    t=read();
    while(t--)
    {
        q.clear();
        n = read(), m = read(),k=read(),p=read(),xx=read(),r=read(),mod=read();
        for(long long i=1; i<=k; ++i) a[i] = read();
        for(long long i=k+1;i<=n;i++)
        {
            a[i]=((p*a[i-1])%mod+xx*i+r)%mod;
        }
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        long long ans=0,count=0;
        for(long long i=1; i<=n; ++i)
        {
            if(i>m && q.front()==a[i-m]) q.pop_front();
            while(!q.empty() && q.back()<a[i]) q.pop_back();
            q.push_back(a[i]);
            if(i>=m)
            {
                //cout<<q.front()<<" "<<(i-m+1)<<endl;
                ans+=q.front()^(i-m+1);
            }
        }
        q.clear();
        for(long long i=1;i<=n/2;i++)
        {
            swap(a[i],a[n-i+1]);
        }

        for(long long i=1; i<=n; ++i)
        {
            if(i>m && q.front()==a[i-m]) q.pop_front();
            while(!q.empty() && q.back()<=a[i]) q.pop_back();
            q.push_back(a[i]);
            if(i>=m)
            {
                //cout<<q.size()<<" "<<(n-i+1)<<endl;
                count+=q.size()^((n-i+1));
            }
        }
        cout<<ans<<" "<<count<<endl;
    }

}
/*
10
10 6 1 3 4 5 10000
3
*/
