#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<deque>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<cstdio>
#define MOD 1000000007
#define fir first
#define sec second
#define mes(x, m) memset(x, m, sizeof(x))
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define INF 1e9+7
#define inf 0x3f3f3f3f

#define Pi 4.0*atan(1.0)
#define Sqrt(x) (x)*(x)

#define lowbit(x) (x&(-x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-12;
const int maxn = 200000+10;
using namespace std;
inline int read(){
    int x(0),f(1);
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int idx;
struct node{
    int f[3];
    int id; //标记多个最短距离取第一个输入的数据
    bool operator<(const node &t)const{
        return f[idx]<t.f[idx];
    }
}data[maxn],kd[maxn<<2];
int flag[maxn<<2];
pair<ll,node> res;
void build(int l,int r,int rt,int dept)
{
    if(l>r)return;
    flag[rt]=1;
    flag[rt<<1]=flag[rt<<1|1]=-1;
    idx=dept%2;
    int mid=(l+r)>>1;
    nth_element(data+l,data+mid,data+r+1);
    kd[rt]=data[mid];
    build(l,mid-1,rt<<1,dept+1);
    build(mid+1,r,rt<<1|1,dept+1);
}
inline ll getDis(int rt,node p)　//求距离
{
    return (ll)Sqrt((ll)p.f[0]-kd[rt].f[0])+(ll)Sqrt((ll)p.f[1]-kd[rt].f[1]);
}
void query(node p,int rt,int dept)
{
    if(flag[rt]==-1)return;
    pair<ll,node> cur{getDis(rt,p),kd[rt]};
    int idm=dept%2;
    bool fg=false;
    int x=rt<<1;
    int y=rt<<1|1;
    if(p.f[idm]>=kd[rt].f[idm]){
        swap(x,y);
    }
    if(~flag[x]){
        query(p,x,dept+1);
    }
    if(res.fir==-1){　//取第一个
        if(cur.sec.f[2]<=p.f[2]){
            res.fir=cur.fir,res.sec=cur.sec;
        }
        fg=true;
    }
    else{
        if(cur.sec.f[2]<=p.f[2]&&(cur.fir<res.fir||(cur.fir==res.fir&&cur.sec.id<res.sec.id))){
            res.fir=cur.fir,res.sec=cur.sec;
        }
        if((ll)Sqrt(kd[rt].f[idm]-p.f[idm])<res.fir){
            fg=true;
        }
    }
    if(~flag[y]&&fg){
        query(p,y,dept+1);
    }
}
int main()
{
  // fin;
    int t,n,m;
    t=read();
    while(t--){
        n=read(),m=read();
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j){
                data[i].f[j]=read();
            }
            data[i].id=i;
        }
        build(0,n-1,1,0);
        while(m--){
            node p;
            for(int i=0;i<3;++i){
                p.f[i]=read();
            }
            res.fir=-1;
            query(p,1,0);
            printf("%d %d %d\n",res.sec.f[0],res.sec.f[1],res.sec.f[2]);
        }
    }
    return 0;
}