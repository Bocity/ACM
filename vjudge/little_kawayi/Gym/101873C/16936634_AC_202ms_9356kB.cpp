#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> s[N];
int rt[N], rc[N];
int dp[N][N];
int x, t, n, m;
struct state
{
    int p, t, c;
};
queue<state> q;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(dp, 0x3f, sizeof dp);
    cin >> x;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        s[u].push_back(v);
        s[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> rt[i] >> rc[i];
    dp[1][rt[1] ] = rc[1];
    q.push(state{1, rt[1], rc[1]});
    while(!q.empty())
    {
        state now = q.front();
        //cout << now.p << ' ' << now.t << ' ' << now.c << '|' << dp[1][4] << endl;
        q.pop();
        if (now.t + rt[now.p] <= x)
            if (now.c + rc[now.p] < dp[now.p][now.t + rt[now.p] ])
            {
                dp[now.p][now.t + rt[now.p] ] = now.c + rc[now.p];
                q.push(state{now.p, now.t + rt[now.p], now.c + rc[now.p]});
            }
        for (int i : s[now.p])
            if (now.t + rt[i] + t <= x)
                if (now.c + rc[i] < dp[i][now.t + rt[i] + t])
                {
                    dp[i][now.t + rt[i] + t] = now.c + rc[i];
                    q.push(state{i, now.t + rt[i] + t, now.c + rc[i]});
                }
    }
    if (dp[1][x] != 0x3f3f3f3f)
        cout << dp[1][x] << endl;
    else
        cout << "It is a trap." << endl;
    return 0;
}
