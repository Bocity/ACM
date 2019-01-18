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
#define MAXM 55555
#define INF 1e10
using namespace std;
struct EDGE {
    int v, next, w;
} edge[MAXM];      //边
int head[MAXM], e; // head 顶点
int n, k, vis[MAXN], ans, root, num;
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
int mx[MAXM], size[MAXN], mi, dis[MAXM];
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
    dis[num++] = d;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != fa && !vis[v]) dfs_dis(v, d + edge[i].w, u);
    }
}
int calc(int u,int d){
    int ret = 0;
    num = 0;
    dfs_dis(u,d,0);//需要统计所有结点到重心的距离
    sort(dis,dis + num);
    int i = 0, j = num -1;
    while(i < j){
        while (dis[i]+dis[j]>k&& i<j)j--;
        ret+=j-i;
        i++;
        
    }
    return ret;

}

void dfs(int u){
    mi = n;
    dfs_size(u,0);//以每个结点为根的子树大小
    dfs_root(u,u,0);  //从这些结点中找重心
    ans += calc(root,0);
    vis[root] = 1;
    for(int i = head[root]; i != -1; i = edge[i].next){
    int v=edge[i].v;
    if(!vis[v]){
        ans -= calc(v, edge[i].w);
        dfs(v);
    }
 }
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        if(!k&&!n)break;
        init();
        int u,v,w;
        for (int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);

        }
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}