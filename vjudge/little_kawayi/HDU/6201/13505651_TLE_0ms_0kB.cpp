#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x ; i < n; ++i)
using namespace std;
const long long INF = 0x3f3f;
typedef pair<int,int> pii;
int cost[10000]{0};
vector<pii> e[100005];
int max1[100005]{0};
int max2[100005]{0};
bool vis[100005]{0};
void dfs(int rt){
    bool fuck = false;
    REP(i,0,e[rt].size()){
        if (!vis[e[rt][i].first]){
            fuck = true;
            vis[e[rt][i].first] = 1;
            dfs(e[rt][i].first);
            max1[rt] = max(max1[rt],max(max1[e[rt][i].first] - e[rt][i].second,-cost[rt]));
            max2[rt] = max(max2[e[rt][i].first] - e[rt][i].second,max2[rt]);
        }
    }
    if (!fuck){
        max1[rt] = -cost[rt];
        max2[rt] = cost[rt];
    }
}
void init(){
    REP(i,0,100001){
        max1[i] = -INF;
        max2[i] = 0;
        e[i].clear();
    }
    memset(vis,0,sizeof vis);
}
void stay(){
    int n;
    int w;
    init();
    cin >> n;
    REP(i,0,n){
        cin >> w;
        cost[i+1] = w;
    }
    int x,y;
    REP(i,0,n-1){
        cin >> x >> y >> w;
        e[x].push_back(pii(y,w));
        e[y].push_back(pii(y,w));
    }
    dfs(1);
    int ans = 0;
    REP(i,1,n + 1){
        if (i == 1 && e[i].size() == 1 ) continue;
        if (i!=1 && e[i].size() <= 2) continue;
       // cout << i<<" "<<max1[i] << " " << max2[i] << endl;
        ans = max(max(max1[i]+max2[i],ans),cost[i]+max1[i]);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        stay();
    }
    return 0;
}