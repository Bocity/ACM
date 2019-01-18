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
long long ans[maxn][3];
long long flag[maxn];
ll a[maxn];
ll sqr(ll aa){return aa*aa;}
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
        while(R<Q[i].r){
            R++;
            add(R);
        }
        while(R>Q[i].r){
            del(R);
            R--;
        }
        while(L<Q[i].l){
            del(L-1);
            L++;
        }
        while(L>Q[i].l){
            L--;
            add(L-1);
        }
        ans[Q[i].id][0]=Ans-(R-L+1);
        ans[Q[i].id][1]=(R-L+1)*(R-L);
    }
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        Ans=0;
    ll sz = sqrt(n);
    memset(flag,0,sizeof flag);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pos[i]=i/sz;
    }
    for(int i = 1;i<=m ;i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id=i;
    }
    flag[0]=1;
    L=1,R=0,Ans=0;
    work();
    while(1){
        int a1;
    }
    for(int i = 1;i <= m ;i++){
        if (ans[i][0]==0||ans[i][1]==0)
        {
            cout<<0<<"/"<<1<<endl;
        }
        else{
            long long ss=__gcd(ans[i][0],ans[i][1]);
        cout<<ans[i][0]/ss<<"/"<<ans[i][1]/ss<<endl;
    }
    }
    }
    
    return 0;
}