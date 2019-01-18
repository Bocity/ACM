#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6+10;

struct node{
    long long l,r,id;
}Q[maxn];
long long n,m,k;

long long L=1,R=0;
long long Ans=0;
long long pos[maxn];
long long ans[maxn];
long long flag[maxn];
long long a[maxn];
long long get(){  
    long long p=0;char x=getchar();  
    while (x<'0' || x>'9') x=getchar();  
    while (x>='0' && x<='9') p=p*10+x-'0',x=getchar();  
    return p;  
} 
bool cmp ( node a,node b){
    if (pos[a.l]==pos[b.l])
    return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
void add(long long x){
    Ans-=flag[a[x]]*flag[a[x]]*a[x];
    flag[a[x]]++;
    Ans+=flag[a[x]]*flag[a[x]]*a[x];
}
void del (long long x){
    Ans-=flag[a[x]]*flag[a[x]]*a[x] ;
    flag[a[x]]--;
    Ans+=flag[a[x]]*flag[a[x]]*a[x];
}

int main(){
   // ios::sync_with_stdio(false);
   n=get();
   m=get();
    long long sz=sqrt(n);
    for(long long i=1;i<=n;i++){
        a[i]=get();
        pos[i]=i/sz;
    }
    for(long long i=1;i<=m;i++){
        Q[i].l=get();
        Q[i].r=get();
        Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    for(long long i=1;i<=m;i++){
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

        for(long long i=1;i<=m;i++){
             printf("%I64d\n",ans[i]);  
        }
    return 0;
}