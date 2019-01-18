#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int e[101][101];
int match[101];
int book[101];
int n, m,n1,n2;

int dfs(int u) {
    int i;
    for (i = 1; i <= n; i++) {
        if (book[i] == 0 && e[u][i] == 1) {
            book[i] = 1; 
            if (match[i] == 0 || dfs(match[i])) {
                match[i] = u;
                match[u] = i;
                return 1; 
            }
        }
    }
    return 0;
}
int main() {
    int i, j, t1, t2, sum = 0;
    while (~scanf("%d", &n1) && n1 != 0){
        scanf("%d%d",&n2,&m);
        memset(e,0,sizeof e);
        sum = 0;
        n = n1 + n2;
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &t1, &t2);
            t1++;
            t2 += n1 + 1;
            e[t1][t2] = 1;
            e[t2][t1] = 1;
        }
        for (i = 1; i <= n; i++) match[i] = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) book[j] = 0;
            if (dfs(i)) sum++;                  
        }
        printf("%d\n", sum);
    }
    return 0;
}