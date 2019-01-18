#include <bits/stdc++.h>
using namespace std;
int c[100];
int G[30][30];
int n;
bool dfs(int v){
    for(int u = 0; u < v; u++){
        if (G[u][v] && c[u] == c[v]) return false;
    }
    if (v == n- 1) return 1;
    for(int i = 0 ; i < 3; ++i){
        c[v + 1] = i;
        if (dfs(v+1)) return true;
    }
    return false;
}
int main(){
    int T,a,b,m,i;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(G,0,sizeof G);
        for(i = 0; i < m; i++){
            cin >> a >> b;
            G[a][b] = G[b][a] = 1;
        }
        if (dfs(0))puts("Y");
        else puts("N");
    }
    return 0;
}