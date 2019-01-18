#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
const int maxn=1e5+10;
typedef long long LL;

struct node
{
    int l,r;
    node(int _l=0,int _r=0):l(_l),r(_r){}
    bool operator < (const node &t)const {return l<t.l;}
}p[maxn];
multiset<int>st;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n,l,r;
    scanf("%d",&T);
    while(T--)
    {
        st.clear();

        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l,&r);
            p[i]=node(l,r);
        }
        sort(p,p+n);
        LL tol=0,ans=0;
        multiset<int>::iterator it;
        for(int i=0;i<n;i++)
        {
            it=st.upper_bound(p[i].l);
            if(it==st.begin())
            {
                ans+=p[i].r-p[i].l;
                st.insert(p[i].r);
                tol++;
            }
            else
            {
                it--;
                ans+=p[i].r-(*it);
                st.erase(it);
                st.insert(p[i].r);
            }
        }
        printf("%lld %lld\n",tol,ans);
    }
    return 0;
}