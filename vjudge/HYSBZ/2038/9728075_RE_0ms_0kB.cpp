#include <bits/stdc++.h>
using namespace std;
const int maxn = 70001;
typedef long long ll;
struct node{
   ll l,r,id;
}Q[maxn];
ll n,m,k;

ll L=1,R=0,sz;
long long Ans=0;
ll pos[maxn];
long long ans[maxn][13];
long long flag[maxn];
ll a[maxn];
ll sqr(ll aa){return aa*aa;}
bool cmp ( node a,node b){
    if (pos[a.l]==pos[b.l])
    return a.r<b.r;
    return a.l<b.l;
}
void add(int x){
    Ans-=sqr(flag[a[x]]);
    flag[a[x]]+=1;
    Ans+=sqr(flag[a[x]]);
}
void del (int x){
    Ans-=sqr(flag[a[x]]);
    flag[a[x]]-=1;
    Ans+=sqr(flag[a[x]]);
}
void update(ll p,int add)
{
	Ans-=sqr(flag[a[p]]);
	flag[a[p]]+=add;
	Ans+=sqr(flag[a[p]]);
}
void work(){
    sort(Q+1,Q+m+1,cmp);
    for(int i=1;i<=m;i++){
	    for(;R<Q[i].r;R++)
			update(R+1,1);
		for(;R>Q[i].r;R--)
		    update(R,-1);
		for(;L<Q[i].l;L++)
		    update(L,-1);
		for(;L>Q[i].l;L--)
		    update(L-1,1);
        if (Q[i].l==Q[i].r){
             ans[Q[i].id][0]=0;
             ans[Q[i].id][1]=1;
             continue;
        }
        long long ss=__gcd(Ans-(R-L+1),(R-L+1)*(R-L));
        ans[Q[i].id][0]=(Ans-(R-L+1))/ss;
        ans[Q[i].id][1]=(R-L+1)*(R-L)/ss;
    }
}
int main(){
    //ios::sync_with_stdio(false);
    while(cin>>n>>m){
        Ans=0;
    ll sz = (ll)sqrt(n);
    memset(flag,0,sizeof flag);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pos[i]=(i-1)/sz+1;
    }
    for(int i = 1;i<=m ;i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id=i;
    }
   // flag[0]= 1;
    L=1,R=0,Ans=0;
    work();
    for(int i = 1;i <= m ;i++){

        cout<<ans[i][0]<<"/"<<ans[i][1]<<endl;
    }
    }
    
    return 0;
}