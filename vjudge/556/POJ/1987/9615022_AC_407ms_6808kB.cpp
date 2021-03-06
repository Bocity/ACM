/*基于点的分治*/
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
#define MAXN 500010
#define MAXM 500010
#define INF 1000000000
using namespace std;
struct EDGE {
    int v, next, w;
} edge[MAXM];      //边
int head[MAXM], e; // head 顶点
int n, k, vis[MAXN], root, num,m;
long long ans;
int color[MAXN];
long long hash1[1200];
inline void init() {
    memset(vis, 0, sizeof vis);
    memset(head, -1, sizeof head);
    e = ans = 0;
}
inline void add(int u, int v, int w) {
    edge[e].v = v;          //边的目标点
    edge[e].w = w;          //边的权值
    edge[e].next = head[u]; //边的上一个顶点
    head[u] = e++;          //顶点指向这条边
}
int mx[MAXM], size[MAXN], mi ;
int dis[MAXN];
void dfs_size(int u, int fa) {     //统计子结点数量
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
void dfs_disd(int u, int d, int fa) { //模版，统计到重心的距离
    dis[num++] = d;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) dfs_disd(v, d + edge[i].w, u);
    }
}
void dfs_root(int r, int u, int fa) {  //找重心
    if (size[r] - size[u] > mx[u]) mx[u] = size[r] - size[u];
    if (mx[u] < mi) mi = mx[u], root = u;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) dfs_root(r, v, u);
    }
}
long long calc(int u,int d){   //分治的计算部分
    long long ret = 0;
    num = 0;
    dfs_disd(u,d,0);//需要统计所有结点到重心的距离
    sort(dis,dis+num);
    int i=0,j=num-1;
    while(i<j){
        while(dis[i]+dis[j]>m&&i<j)j--;
        ret+=j-i;
        i++;
    }
    return ret;

}


void dfs(int u){  //分治版dfs
    mi = n;
    dfs_size(u,-1);//以每个结点为根的子树大小
    dfs_root(u,u,-1);  //从这些结点中找重心
    ans += calc(root,0);
       vis[root] = 1;
    int rt = root;
    for(int i = head[root]; i != -1; i = edge[i].next){
    int v=edge[i].v;
    if(!vis[v]){
        ans -= calc(v,edge[i].w);//减去子结点中重复的答案
        dfs(v);
    }
 }
}
int main(){
    while(scanf("%d%d",&n,&k)==2){
        init();
        int u,v,w;
        // for(int i=1;i<=n;i++){
        //     scanf("%d",&x);
        //     x--;
        //     color[i]=x;
        // }
        string s;
        for (int i=1;i<=k;i++){
            scanf("%d%d%d",&u,&v,&w);
            cin>>s;
            add(u,v,w);//加边   1为边权
            add(v,u,w);
        }
        scanf("%d",&m);
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}