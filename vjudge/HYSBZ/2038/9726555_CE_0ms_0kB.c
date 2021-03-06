#include <bits/stdc++.h>
using namespace std;
const int maxn = 1<<20;
typedef long long ll;
struct node{
   ll l,r,id;
}Q[maxn];
ll n,m,k;

ll L=1,R=0,sz;
long long Ans=0;
ll pos[maxn];
long long ans[maxn][3];
long long flag[maxn];
ll a[maxn];
ll sqr(ll a){return a*a;}
bool cmp ( node a,node b){
    if (pos[a.l]==pos[b.l])
    return a.r<b.r;
    return pos[a.l]<pos[b.l];
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
void work(){
    sort(Q+1,Q+m+1,cmp);
    for(int i=1;i<=m;i++){
        while(L<Q[i].l){
            del(L-1);
            L++;
        }
        while(L>Q[i].l){
            L--;
            add(L-1);
        }
        while(R<Q[i].r){
            R++;
            add(R);
        }
        while(R>Q[i].r){
            del(R);
            R--;
        }

        ans[Q[i].id][0]=Ans-Q[i].r+Q[i].l-1;
        ans[Q[i].id][1]=(Q[i].r-Q[i].l+1)*(Q[i].r-Q[i].l);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    ll sz = sqrt(n);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pos[i]=(i-1)/sz+1;
    }
    for(int i = 1;i<=m ;i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id=i;
    }
    flag[0]=1;
    L=1,R=0,Ans=0;
    work();
    for(int i = 1;i <= m ;i++){
        if (ans[i][0]==0)
        {
            cout<<0<<"/"<<1<<endl;
        }
        else{
        cout<<ans[i][0]/__gcd(ans[i][0],ans[i][1])<<"/"<<ans[i][1]/__gcd(ans[i][0],ans[i][1])<<endl;
    }
    }
    
    return 0;
}