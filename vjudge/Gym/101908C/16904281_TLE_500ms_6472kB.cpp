#include<bits/stdc++.h>
using namespace std;
int sum[100005];
int n;
void add(int p, int x)
{
    while(p <= n) sum[p] += x, p += p & -p;
}
int ask(int p)
{
    int res = 0;
    while(p) res += sum[p], p -= p & -p;
    return res;
}
struct P
{
    int x,y;
    bool operator<(P a)
    {
        return x>a.x;
    }
};
P a[100005];
int q[100005];
unordered_map<int,int> mp1,mp2;
int main()
{
    int x,y,h,v,p,l;
    long long ans=0;
    cin>>x>>y>>h>>v;
    for(int i=0;i<h;++i)
    {
        cin>>a[i].x>>a[i].y;
        q[i]=a[i].y;
    }
    sort(a,a+h);
    sort(q,q+h);
    l=unique(q,q+h)-q;
    for(int i=0;i<l;++i)
    {
        mp1[q[i]]=i+1;
    }
    n=l;
    for(int i=0;i<h;++i)
    {
        ans+=ask(mp1[a[i].y]);
        add(mp1[a[i].y],1);
    }
    for(int i=0;i<v;++i)
    {
        cin>>a[i].x>>a[i].y;
        q[i]=a[i].y;
    }
    sort(a,a+v);
    sort(q,q+v);
    l=unique(q,q+v)-q;
    for(int i=0;i<l;++i)
    {
        mp2[q[i]]=i+1;
    }
    n=l;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<v;++i)
    {
        ans+=ask(mp2[a[i].y]);
        add(mp2[a[i].y],1);
    }
    cout<<(h+1ll)*(v+1ll)+ans;
    return 0;
}