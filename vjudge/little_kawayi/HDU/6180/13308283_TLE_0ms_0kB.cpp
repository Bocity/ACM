#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
struct plan
{
    int s;
    int t;
    friend bool operator < (plan x,plan y)
    {
        return x.t < y.t || (x.t == y.t && x.s < y.s);
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        plan *p = new plan[n];
        bool *vis = new bool[n];
        memset(vis, 0, n);
        for (int i = 0; i < n; i++)
            cin >> p[i].s >> p[i].t;
        sort(p, p + n);
        int cnt = 0,ans = 0,lst = n;
        while(lst)
        {
            int b = -1;
            int e = 0;
            for (int i = 0; i < n; i++)
                if (!vis[i] && p[i].s > e)
                {
                    vis[i] = 1;
                    e = p[i].t;
                    if (b == -1)
                        b = p[i].s;
                        lst--;
                }
            ans+= e - b;
            cnt++;
        }
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}