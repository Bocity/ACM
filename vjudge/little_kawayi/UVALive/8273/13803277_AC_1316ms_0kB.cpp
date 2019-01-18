#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int a=1,b=1;
int cou=0;
int graph[28][28]={0};
int color[28]={0};

inline bool ok(int c){
    for(int k=1;k<=n;k++){
        if(graph[c][k]&&color[c]==color[k]){
            return false;
        }
    }
    return true;
}

void backtrack(int cur){
    if (cou) return ;
    if(cur>n){
        cou++;
    }else{
        for(int i=1;i<=m;i++){
            color[cur]=i;
            if(ok(cur)){
    if (cou) return ;                backtrack(cur+1);
            }
            color[cur]=0;
        }
    }
}

int main()
{
    int t;
    int p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&p);
        m = 3;
        cou = 0;
        memset(graph,0,sizeof graph);
        memset(color,0,sizeof color);
        for(int i = 0; i < p; ++i){
            scanf("%d%d",&a,&b);
            a++;
            b++;
            graph[a][b]=1;
            graph[b][a]=1;
        }
        backtrack(1);
        if (cou > 0){
            puts("Y");
        }else{
            puts("N");
        }
    }
    return 0;
}