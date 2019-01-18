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
#define endl "\n"
int main()
{
    long long t;
    t=read();
    while(t--)
    {
        q.clear();
        n = read(), m = read(),k=read(),p=read(),xx=read(),r=read(),mod=read();
        for(long long i=n; i>(n-k); i--) a[i] = read();
        for(long long i=(n-k);i>=1;i--)
        {
            a[i]=((p*a[i+1])+xx*(n-i+1)+r)%mod;
        }
        long long ans=0,count=0;

        for(long long i=1; i<=n; ++i)
        {
            if(i>m && q.front()==a[i-m]) q.pop_front();
            while(!q.empty() && q.back()<=a[i]) q.pop_back();
            q.push_back(a[i]);
            if(i>=m)
            {
                count+=q.size()^((n-i+1));
                ans+=q.front()^(n-i+1);
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