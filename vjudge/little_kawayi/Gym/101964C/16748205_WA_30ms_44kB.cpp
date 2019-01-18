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
    cin.tie(0);
    ios::sync_with_stdio(0);
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
            if (i != j)
            {
                int cnt = c[i] + c[j];
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
    cout << ans << endl;
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

9 4
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/
