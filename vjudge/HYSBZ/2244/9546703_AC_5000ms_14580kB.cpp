#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 100005
#define LL long long

int n;
double ans,down;
int lsh[N],LSH;
struct data{int x,y,id;}q[N];
double f[N],h[N],g[N],k[N];

namespace FG
{
    double C[N],D[N];
    double maxf,maxg;
    data a[N],b[N];int ch[N];
    int cmp(data a,data b)
    {
        return a.x>b.x;
    }
    void add(int loc,double valf,double valg)
    {
        for (int i=loc;i<=LSH;i+=i&-i)
            if (valf>C[i]) C[i]=valf,D[i]=valg;
            else if (valf==C[i]) D[i]+=valg;
    }
    void query(int loc)
    {
        maxf=0,maxg=0;
        for (int i=loc;i>=1;i-=i&-i)
            if (C[i]>maxf) maxf=C[i],maxg=D[i];
            else if (C[i]==maxf) maxg+=D[i];
    }
    void cover(int loc)
    {
        for (int i=loc;i<=LSH;i+=i&-i)
            C[i]=0,D[i]=0;
    }
    void cdq(int l,int r)
    {
        if (l==r)
        {
            f[l]=max(f[l],1.0);
            g[l]=max(g[l],1.0);
            return;
        }
        int mid=(l+r)>>1;
        cdq(l,mid);
        int acnt=0,bcnt=0;
        for (int i=l;i<=mid;++i) a[++acnt]=q[i];
        for (int i=mid+1;i<=r;++i) b[++bcnt]=q[i];
        sort(a+1,a+acnt+1,cmp);sort(b+1,b+bcnt+1,cmp);
        int pa=1,pb=1,tot=0;
        while (pb<=bcnt)
        {
            while (pa<=acnt&&a[pa].x>=b[pb].x)
            {
                add(LSH-a[pa].y+1,f[a[pa].id],g[a[pa].id]);
                ch[++tot]=LSH-a[pa].y+1;
                ++pa;
            }
            query(LSH-b[pb].y+1);
            int now=b[pb].id;
            if (f[now]<maxf+1) f[now]=maxf+1,g[now]=maxg;
            else if (f[now]==maxf+1) g[now]+=maxg;
            ++pb;
        }
        for (int i=1;i<=tot;++i) cover(ch[i]);
        cdq(mid+1,r);
    }
    void solve()
    {
        cdq(1,n);
    }
}
namespace HK
{
    double C[N],D[N];
    double maxh,maxk;
    data a[N],b[N];int ch[N];

    int cmp(data a,data b)
    {
        return a.x>b.x;
    }
    void add(int loc,double valh,double valk)
    {
        for (int i=loc;i<=LSH;i+=i&-i)
            if (valh>C[i]) C[i]=valh,D[i]=valk;
            else if (valh==C[i]) D[i]+=valk;
    }
    void query(int loc)
    {
        maxh=0,maxk=0;
        for (int i=loc;i>=1;i-=i&-i)
            if (C[i]>maxh) maxh=C[i],maxk=D[i];
            else if (C[i]==maxh) maxk+=D[i];
    }
    void cover(int loc)
    {
        for (int i=loc;i<=LSH;i+=i&-i)
            C[i]=0,D[i]=0;
    }
    void cdq(int l,int r)
    {
        if (l==r)
        {
            h[l]=max(h[l],1.0);
            k[l]=max(k[l],1.0);
            return;
        }
        int mid=(l+r)>>1;
        cdq(mid+1,r);
        int acnt=0,bcnt=0;
        for (int i=l;i<=mid;++i) a[++acnt]=q[i];
        for (int i=mid+1;i<=r;++i) b[++bcnt]=q[i];
        sort(a+1,a+acnt+1,cmp);sort(b+1,b+bcnt+1,cmp);
        int pa=acnt,pb=bcnt,tot=0;
        while (pa>=1)
        {
            while (pb>=1&&b[pb].x<=a[pa].x)
            {
                add(b[pb].y,h[b[pb].id],k[b[pb].id]);
                ch[++tot]=b[pb].y;
                --pb;
            }
            query(a[pa].y);
            int now=a[pa].id;
            if (h[now]<maxh+1) h[now]=maxh+1,k[now]=maxk;
            else if (h[now]==maxh+1) k[now]+=maxk;
            --pa;
        }
        for (int i=1;i<=tot;++i) cover(ch[i]);
        cdq(l,mid);
    }
    void solve()
    {
        cdq(1,n);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&q[i].x,&q[i].y);
        lsh[++LSH]=q[i].y;q[i].id=i;
    }
    sort(lsh+1,lsh+LSH+1);LSH=unique(lsh+1,lsh+LSH+1)-lsh-1;
    for (int i=1;i<=n;++i) q[i].y=lower_bound(lsh+1,lsh+LSH+1,q[i].y)-lsh;
    for (int i=1;i<=n;++i)
    f[1]=1;g[1]=1;
    FG::solve();
    for (int i=1;i<=n;++i) ans=max(ans,f[i]);
    printf("%.0lf\n",ans);
    for (int i=1;i<=n;++i)
        if (f[i]==ans) down+=g[i];
    h[n]=1;k[n]=1;
    HK::solve();
    double zero=0.0;
    for (int i=1;i<=n;++i)
        if (f[i]+h[i]-1==ans)
            printf("%.5lf%c",g[i]*k[i]/down," \n"[i==n]);
        else printf("%.5lf%c",zero," \n"[i==n]);
}