#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#define eps 1e-5
#define MAXN 11111
#define MAXM 555555
#define INF 1000000000
using namespace std;
struct EDGE {
    int v, next, w;
} edge[MAXM<<1];      //边
int head[MAXM], e; // head 顶点
int n, k, vis[MAXN], ans, root, num,m;
int color[MAXN];
int hash1[MAXN];
void init() {
    memset(vis, 0, sizeof vis);
    memset(head, -1, sizeof head);
    e = ans = 0;
}
void add(int u, int v, int w) {
    edge[e].v = v;          //边的目标点
    edge[e].w = w;          //边的权值
    edge[e].next = head[u]; //边的上一个顶点
    head[u] = e++;          //顶点指向这条边
}
int mx[MAXM], size[MAXN], mi ;
vector<int > dis;
void dfs_size(int u, int fa) {
    size[u] = 1;
    mx[u] = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) {
            dfs_size(v, u);
            size[u] += size[v];
            if (size[v] > mx[u]) mx[u] = size[v];
        }
    }
}
void dfs_root(int r, int u, int fa) {
    if (size[r] - size[u] > mx[u]) mx[u] = size[r] - size[u];
    if (mx[u] < mi) mi = mx[u], root = u;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) dfs_root(r, v, u);
    }
}
void dfs_dis(int u, int d, int fa) {
    dis.push_back(d);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) dfs_dis(v, (d|(1<<color[v])), u);
    }
}
int calc(int u,int d){
    int ret = 0;
    memset(hash1,0,sizeof hash1);
    num = 0;
    dis.clear();
    dfs_dis(u,d,0);//需要统计所有结点到重心的距离
    int cnt=dis.size();
    for(int i=0;i<cnt;i++) hash1[dis[i]]++;
    for(int i=0;i<cnt;i++){
        hash1[dis[i]]--;
        ret+=hash1[(1<<k)-1];
        //cout<<ret<<endl;
        for(int s0=dis[i];s0;s0=(s0-1)&dis[i]){
            ret+=hash1[((1<<k)-1)^s0];
        }
        hash1[dis[i]]++;
    }
    return ret;

}

void dfs(int u){
    mi = n;
   // cout<<1<<endl;
    dfs_size(u,0);//以每个结点为根的子树大小
    //cout<<1<<endl;
    dfs_root(u,u,0);  //从这些结点中找重心
   // cout<<ans<<endl;
    ans += calc(root,(1<<color[root]));
  // cout<<ans<<endl;
    vis[root] = 1;
    int rt = root;
    for(int i = head[root]; i != -1; i = edge[i].next){
    int v=edge[i].v;
    if(!vis[v]){
        ans -= calc(v,((1<<color[rt])|(1<<color[v])) );
        dfs(v);
    }
 }
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        init();
        int u,v,w,x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            x--;
            color[i]=x;
        }
        for (int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v,1);
            add(v,u,1);
        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}