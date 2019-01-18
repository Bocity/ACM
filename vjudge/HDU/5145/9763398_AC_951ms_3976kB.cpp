#include <bits/stdc++.h>
using namespace std;
const long long maxn =52000;
const long long mod = 1000000007;
typedef long long ll;
struct node{
    long long l,r,id;
}Q[maxn];
long long n,m,k;
long long L=1,R=0;
long long Ans=0;
long long pos[maxn];
long long inv[maxn];
long long ans[maxn];
long long flag[maxn];
long long a[maxn];
bool cmp (node a,node b){
    if (pos[a.l]==pos[b.l])
    return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
inline long long pow_mod(long long a,long long n)  
{  
    long long ans=1;  
    while(n)  
    {  
        if(n&1) ans=ans*a%mod;  
        a=a*a%mod;  
        n>>=1;  
    }  
    return ans;  
}
long long getinv(long long n)  
{  
    return pow_mod(n,mod-2);  
}

int main(){
    ios::sync_with_stdio(false);
    long long T;
    cin>>T;
    for(long long i=1; i<maxn; i++)  
            inv[i]=getinv(i);  
   while (T--){
    Ans=1;
    cin>>n>>m;
        
    long long sz=sqrt(n);
        for(long long i=1;i<=n;++i){
            cin>>a[i];
            pos[i]=i/sz;
        }
        for(long long  i=1;i<=m;++i){
            cin>>Q[i].l>>Q[i].r;
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
        L=1,R=0;
        memset(flag,0,sizeof flag);
        for(long long i=1;i<=m;++i){
           while(R>Q[i].r){
                Ans=Ans*inv[R-L+1]%mod*flag[a[R]]%mod; 
                flag[a[R]]--;  
                R--;
            }
            while(R<Q[i].r){
                R++;
                flag[a[R]]++;
                Ans=Ans*(R-L+1)%mod*inv[flag[a[R]]]%mod;
            }
            while(L<Q[i].l){
                Ans=Ans*inv[R-L+1]%mod*flag[a[L]]%mod; 
                flag[a[L]]--;
                L++;
            }
            while(L>Q[i].l){
                L--;
                flag[a[L]]++;
                Ans=Ans*(R-L+1)%mod*inv[flag[a[L]]]%mod;
            }
            ans[Q[i].id]=Ans;
        }

        for(long long  i=1;i<=m;++i){
                cout<<ans[i]<<"\n";
         }
   }
    return 0;
}