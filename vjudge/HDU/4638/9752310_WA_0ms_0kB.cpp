#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6+10;
typedef long long ll;
struct node{
    int l,r,id;
}Q[maxn];
int n,m,k;
int L=1,R=0;
long long Ans=0;
int pos[maxn];
long long ans[maxn];
int flag[maxn];
int a[maxn];
inline long long sqr(int x){
    return (ll)x*(ll)x;
}
inline int get(){  
    int p=0;char x=getchar();  
    while (x<'0' || x>'9') x=getchar();  
    while (x>='0' && x<='9') p=p*10+x-'0',x=getchar();  
    return p;  
} 
bool cmp (node a,node b){
    if (pos[a.l]==pos[b.l])
    return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
inline void add(int x){
    flag[a[x]]=1;
    if (flag[a[x]-1]==1&&flag[a[x]+1]==1){
        Ans--;
    }
    if (flag[a[x]-1]==0&&flag[a[x]+1]==0){
        Ans++;
    }
}
inline void del (int x){
    flag[a[x]]=0;
    if (flag[a[x]-1]==1&&flag[a[x]+1]==1){
        Ans++;
    }
    if (flag[a[x]-1]==0&&flag[a[x]+1]==0){
        Ans--;
    }
}

int main(){
   // ios::sync_with_stdio(false);
   int T;
   T =get();
   while (T--){
    Ans=0;
    memset(flag,0,sizeof flag);
    n=get();
    m=get();
    int sz=sqrt(n);
        for(int i=1;i<=n;++i){
            a[i]=get();
            pos[i]=i/sz;
        }
        for(int  i=1;i<=m;++i){
            Q[i].l=get();
            Q[i].r=get();
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
        for(int i=1;i<=m;++i){
            if (Q[i].l==Q[i].r) {  
                ans[Q[i].id]=a[Q[i].l];  
                continue;  
            } 
            while(L<Q[i].l){
                del(L);
                L++;
            }
            while(L>Q[i].l){
                L--;
                add(L);
            }
            while(R<Q[i].r){
                R++;
                add(R);
            }
            while(R>Q[i].r){
                del(R);
                R--;
            }
                ans[Q[i].id]=Ans;
        }

            for(int  i=1;i<=m;++i){
                printf("%lld\n",ans[i]);  
            }
   }
    return 0;
}