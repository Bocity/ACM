#include <bits/stdc++.h>
using namespace std;
int dis[101][101], c[101];
vector<int> s[101];
int num;
void dfs(int x, int p)
{
    for (int i : s[x])
        if (i != p)
            dis[num][i] = dis[num][x] + 1,
            dfs(i, x);
}
int main()
{
    //freopen("C:\\Users\\12943\\Desktop\\test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        s[u].push_back(v);
        s[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        num = i;
        dfs(i, 0);
    }
    int ans = 101;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (c[i] && c[j] && i != j)
            {
                int cnt = 2;
                if (cnt >= m)
                {
                    ans = min(dis[i][j], ans);
                    goto next;
                }
                for (int k = 1; k <= n; k++)
                    if (c[k] && k != i && k != j)
                    {
                    	
                        if (dis[k][i] <= dis[i][j] && dis[k][j] <= dis[i][j])
                            cnt++;
                        if (cnt >= m)
                        {
                            ans = min(dis[i][j], ans);
                            goto next;
                        }
                    }
            }
            next:;
        }
    cout << ((ans == 101 || m == 1) ? 0 : ans) << endl;
    return 0;
}
/*
6 3
1 1 0 1 1 1
1 2
1 3
1 4
3 5
3 6

*/