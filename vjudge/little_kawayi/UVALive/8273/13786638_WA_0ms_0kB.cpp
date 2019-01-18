#include <bits/stdc++.h>
using namespace std;
int Edge[50][50];
int n;
int ans ,c[50];
int b[50];
void greedy(){
    int i,k;
    for(int i = 0; i < n; ++i){
        memset(b,0,sizeof b);
        for(k = 0; k < n; ++k){
            if (Edge[i][k] && c[k] != -1){
                b[c[k]] = 1;
            }
        }
        for(k = 0 ; k <=i; ++k){
            if (!b[k]) break;
        }
        c[i] = k;
    }
    for(i = 0; i <n ; ++i){
        if (ans < c[i]) ans = c[i];
    }
    ans ++;
}
int main(){
    int i,k,t,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(Edge,0,sizeof Edge);
        for(i = 0; i < n; ++i){
            c[i] = -1;
        }
        ans = 0;
        scanf("%d",&p);
        for(i = 0; i < p; ++i){
            int x,y;
            scanf("%d%d",&x,&y);
            Edge[x][y] = 1;
            Edge[y][x] = 1;
        }
        greedy();
        if (ans <= 3){
            puts("Y"); 
        }else{
            puts("N");
        }
    }
    return 0;
}