#include<cmath>
#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int M=50005;
typedef long long ll;
struct Query{
    int L,R,id;
}q[M];
int s,col[M];
ll ans[M][2],cnt[M];
bool cmp(Query a,Query b){
    if(a.L/s==b.L/s) return a.R<b.R;
    return a.L/s<b.L/s;
}
int gcd(ll a,ll b){
    return a?gcd(b%a,a):b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    s=(int)sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        q[i]=(Query){a,b,i};
    }
    sort(q,q+m,cmp);
    int L=1,R=0;
    ll res=0;
    for(int i=0;i<m;i++){
        while(R<q[i].R){
            R++;
            res+=(cnt[col[R]]+1)*(cnt[col[R]]+1)-cnt[col[R]]*cnt[col[R]];
            cnt[col[R]]++;
        }
        while(L<q[i].L){
            res-=cnt[col[L]]*cnt[col[L]]-(cnt[col[L]]-1)*(cnt[col[L]]-1);
            cnt[col[L]]--;
            L++;
        }
        while(R>q[i].R){
            res-=cnt[col[R]]*cnt[col[R]]-(cnt[col[R]]-1)*(cnt[col[R]]-1);
            cnt[col[R]]--;
            R--;
        }
        while(L>q[i].L){
            L--;
            res+=(cnt[col[L]]+1)*(cnt[col[L]]+1)-cnt[col[L]]*cnt[col[L]];
            cnt[col[L]]++;
        }
        ans[q[i].id][0]=res-R+L-1;
        ans[q[i].id][1]=1LL*(R-L+1)*(R-L);
    }
    for(int i=0;i<m;i++){
        int G=gcd(ans[i][0],ans[i][1]);
        ans[i][0]/=G;
        ans[i][1]/=G;
        if(!ans[i][0]) ans[i][1]=1;
    }
    for(int i=0;i<m;i++)
       cout<<ans[i][0]<<"/"<<ans[i][1]<<endl;
    return 0;
}