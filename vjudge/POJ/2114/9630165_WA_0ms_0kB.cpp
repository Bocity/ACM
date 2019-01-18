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
map<long long,int> f;
inline void init() {
    memset(vis, 0, sizeof vis);
    f.clear();
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
int calc(int u,int d){   //分治的计算部分
    long long ret = 0;
    num = 0;
    dfs_disd(u,d,0);//需要统计所有结点到重心的距离
    //cout<<num<<"------"<<u<<endl;
    sort(dis,dis+num);
    int i=0,j=num-1;
    while(i<j){
        if (dis[i]+dis[j]<m)i++;
        else if(dis[i]+dis[j]>m)j--;
        else{
            if (dis[i]==dis[j]){
                ret +=(j-i)*(j-i+1)/2;
                break;
            }
            int st=i,ed=j;
            while(dis[st]==dis[i])st++;
            while(dis[ed]==dis[j])ed--;
            ret+= (st-i)*(j-ed);
            i=st,j=ed;
        }
    }
    return ret;
}

void dfs(int u){  //分治版dfs
    mi = n;
    dfs_size(u,0);//以每个结点为根的子树大小
    dfs_root(u,u,0);  //从这些结点中找重心
    ans+=calc(root,0);
   // cout<<ans<<"-------"<<endl;
    vis[root] = 1;
    int rt = root;
    for(int i = head[root]; i != -1; i = edge[i].next){
    int v=edge[i].v;
    if(!vis[v]){
        ans-=calc(v,edge[i].w);//减去子结点中重复的答案
        dfs(v);
    }
 }
}
int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
        init();
        int u,v,w;
        for(int i=1;i<=n;i++){
            while(scanf("%d",&v)!=EOF&&v!=0){
                scanf("%d",&w);
                add(v,i,w);
                add(i,v,w);
            }
        }

      //  for(int i=1;i<=100;i++) cout<<" "<<f[i];
        while(scanf("%d",&m)!=EOF&&m!=0){
                memset(vis, 0, sizeof vis);
            ans=0;
            dfs(1);
            if (ans>0){
                printf("AYE\n");

            }
            else{
                printf("NAY\n");
            }
        }
        
    }
    printf(".\n");
    return 0;
}