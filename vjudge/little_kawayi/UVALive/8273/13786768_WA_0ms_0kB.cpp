#include <bits/stdc++.h>
#define maxn 360
#define _ll __int64
#define ll long long
#define INF 0x3f3f3f3f
#define Mod 1000000007
#define pp pair<int,int>
#define ull unsigned long long
#define max(x,y) ( ((x) > (y)) ? (x) : (y) )
#define min(x,y) ( ((x) > (y)) ? (y) : (x) )
using namespace std;
int n, ans, ok, vis[28];
bool ma[28][28];
bool check(int u, int sb)
{
    for (int i = 1; i <= n; i++)
        if (ma[u][i] && vis[i] == sb) {
            return 0;
        }
 
    return 1;
}
void dfs(int u, int s)
{
 
    if (ok) {
        return ;
    }
 
    if (u == n + 1) {
        ans = s;
        ok = 1;
        return ;
    }
 
    for (int k = 1; k <= s; k++) {
        if (check(u, k)) {
            vis[u] = k;
            dfs(u + 1, s);
        }
    }
 
    vis[u] = ++s;
    dfs(u + 1, s);
}
int main()
{
    char s[38];
    int t,p;
    scanf("%d",&t);
    while (t--) {
        scanf("%d", &n);
        memset(ma, 0, sizeof(ma));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &p);
        for(int i = 0; i < p; ++i){
            int x, y;
            scanf("%d%d",&x,&y);
            ma[x][y] = 1;
            ma[y][x] = 1;
        }
        ok = 0;
        dfs(1, 1);
        if (ans == 3) {
            puts("Y");
        } else {
            puts("N");
        }
    }
 
    return 0;
}