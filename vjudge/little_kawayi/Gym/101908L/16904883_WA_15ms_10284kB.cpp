#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100050;

int depth[N];

int f[N][20]; // f数组
ll dir[N]; // 每个点到根结点的路径长度

struct edge{
  int to;
  int w;
};
vector<edge> E[N];//邻接表存图

bool used[N];
void dfs(int u){ //预处理dfs
  used[u] = true;
  for(int i=1;i<=15;++i){
    f[u][i] = f[ f[u][i-1] ][i-1]; //计算f数组
  }

  for(edge e:E[u])
    if (!used[e.to]){
      depth[e.to] = depth[u]+1;
      f[e.to][0] = u; // f初值即为父亲结点
      dir[e.to] = dir[u] + e.w;
      dfs(e.to);
    }
}

int LCA(int u,int v){
  if (depth[u] < depth[v]) swap(u,v);// 1.若u高于v，交换。使u低于v。

  for(int i=15;i>=0;--i) // 2.使u爬到和v一样高
    if (depth[ f[u][i] ] >= depth[v]) // 若f[u][i]不高于v则向上爬
      u = f[u][i];

  if (u == v) return u;// u为v的子结点的情况

  for(int i=15;i>=0;--i) // 3.同步倍增
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }

  return f[u][0]; // u和v在不同子树上的情况, 此时必有f[u][0] = f[v][0] = lca
}
bool check(int a1,int b1,int a2,int b2)
{
    int jc;
    int a=a1,b=b1,x=a2,y=b2;
         int L1=LCA(a,b),L2=LCA(x,y);
         if(dir[L1]>dir[L2]) swap(L1,L2),swap(a,x),swap(b,y);
         if(LCA(L2,a)==L2||LCA(L2,b)==L2)
            jc=1;
        else
         jc=0;
}
struct node
{
    int dep,x;

    bool operator <( node &a)const
    {
        return dep<a.dep;
    }
};
int main(){
  // std::ios::sync_with_stdio(false);

  int n,m;
  while(scanf("%d%d",&n,&m) != EOF){
    // 读入数据
    for(int i=0;i<=n;++i) {
      vector<edge>().swap(E[i]);
    }
    int o,p,q;
    for(int i=0;i<n-1;++i){
      scanf("%d%d",&o,&p);
      E[o].push_back({p,1});
      E[p].push_back({o,1});
    }
    // 预处理
    memset(used,0,sizeof used);
    depth[1] = 0; // 根结点的depth
    f[1][0] = 0; // 根结点的f, 所有f的越界值都为根结点的f
    dir[1] = 0;
    dfs(1);
    // 在线处理询问
    for(int i=0;i<m;++i){
      int a1,b1,a2,b2;
      cin>>a1>>b1>>a2>>b2;
      if(min(dir[a1],dir[b1])>min(dir[a2],dir[b2]))
      {
          swap(a1,a2);
          swap(b1,b2);
      }
      int x1,x2,y1,y2;
      x1=LCA(a1,a2);
      x2=LCA(a1,b2);
      y1=LCA(b1,a2);
      y2=LCA(b1,b2);
      if(check(a1,b1,a2,b2))
      {
          node pos[4];
          pos[0].x=x1,pos[0].dep=dir[x1];
          pos[1].x=x2,pos[1].dep=dir[x2];
          pos[2].x=y1,pos[2].dep=dir[y1];
          pos[3].x=y2,pos[3].dep=dir[y2];
          sort(pos,pos+4);
          cout<<dir[pos[2].x]+dir[pos[3].x]-2*dir[LCA(pos[2].x,pos[3].x)]+1<<endl;
      }else
      {
          cout<<0<<endl;
      }

    }
  }
}
