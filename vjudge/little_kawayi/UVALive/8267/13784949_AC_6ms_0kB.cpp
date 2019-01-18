#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
// #define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
// const int maxn = 1000000 + 10;
/*ISAP邻接表形式
*/
const int maxn=1010;//点数的最大值
const int maxm=40010;//边数的最大值
const int inf=0x3f3f3f3f;
struct Edge {
  int to,next,cap,flow;
}edge[maxm];//注意是maxm
int tol;
int head[maxn];
int cur[maxn],d[maxn];// 当前弧下标   结点到汇点距离下界
int p[maxn],gap[maxn];//可增广路上的上一条弧   gap优化  //比dinic多的两个数组
void init() {
  tol=0;
  memset(head,-1,sizeof(head));
}

//加边，单向图三个参数，双向图四个参数
void addedge(int u,int v,int w,int rw=0) {
  edge[tol].to=v; edge[tol].cap=w; edge[tol].next=head[u];
  edge[tol].flow=0; head[u]=tol++;
  edge[tol].to=u; edge[tol].cap=rw; edge[tol].next=head[v];
  edge[tol].flow=0; head[v]=tol++;
}

//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int s,int t,int N){
  memset(gap, 0, sizeof(gap));
  memset(d, 0, sizeof(d));
  memcpy(cur, head, sizeof(head));
  int u=s;
  p[u]=-1;
  gap[0]=N;
  int ans=0;
  while(d[s]<N){
    if(u == t){
      int Min=inf;
      for(int i=p[u]; i!=-1; i=p[edge[i^1].to])//找最小残量值
        if(Min>edge[i].cap-edge[i].flow)
          Min=edge[i].cap-edge[i].flow;
      for(int i = p[u]; i!=-1; i=p[edge[i^1].to]){//增广
        edge[i].flow+=Min;
        edge[i^1].flow-=Min;
      }
      u=s;
      ans+=Min;
      continue;
    }
    bool ok=false;
    int v;
    for(int i=cur[u]; i!=-1; i=edge[i].next){
        v=edge[i].to;
        if(edge[i].cap-edge[i].flow && d[v]+1==d[u]){//Advance前进
          ok=true;
          cur[u]=p[v]=i;
          break;
        }
    }
    if(ok){
      u=v;
      continue;
    }
    //Retreat走不动了，撤退
    int Min=N;
    for(int i=head[u]; i!=-1; i=edge[i].next)
      if(edge[i].cap-edge[i].flow && d[edge[i].to] < Min){
        Min=d[edge[i].to];
        cur[u]=i;
      }
    gap[d[u]]--;
    if(!gap[d[u]])return ans;
    d[u] = Min+1;
    gap[d[u]]++;
    if(u!=s) u=edge[p[u]^1].to;//退一步，沿父边返回
  }
  return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m, s, t, k, x, y;
        cin >> n >> m >> s >> t >> k;
        init();
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            addedge(x, y, 1, 1);
        }
        int ttt = k / 3;
        if(k % 3) ttt += 1;
        cout << sap(s, t, n) * ttt << endl; 
    }
    return 0;
}