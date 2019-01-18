//思路：找到不满足dist[v] < dist2[v] <= k的dist2[v]，更新
/*
时间复杂度：
接口及调用说明：
dist[N - 1]：最短路
dist2[N - 1]：次短路
注意：
*/
#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define INF 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 1000000 + 10;
#define MAXN (5000 + 10)
struct edge{
    int to, cost;
    edge(int tv = 0, int tc = 0):
        to(tv), cost(tc){}
};
typedef pair<int ,int> P;
int N, R;
vector<edge> graph[MAXN];
int dist[MAXN];
int dist2[MAXN];

void solve(){
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    priority_queue<P, vector<P>, greater<P> > Q;
    dist[0] = 0;
    Q.push(P(0, 0));
    while(!Q.empty()){
        P p = Q.top(); 
        Q.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        for(unsigned i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            int d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));
            }
        }
    }
    // cout << dist2[N - 1] << endl;
}

int main(){
    int A, B, D, K;
    int k[maxn];
    scanf("%d%d%d", &N, &R, &K);
    for(int i = 0; i < K; i++) {
        scanf("%d", &k[i]);
        k[i]--;
    }
    for(int i = 0; i < R; i++){
        scanf("%d%d%d", &A, &B, &D);
        graph[A-1].push_back(edge(B-1, D));
        graph[B-1].push_back(edge(A-1, D));
    }
    solve();
    int ans = 0;
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 0; j < graph[i].size(); j++) {
    //         cout << " " << i << " " << graph[i][j].to << " " << graph[i][j].cost << endl;
    //     }
    // }
    for(int i = 0; i < K - 1; i++) {
        for(int j = 0; j < graph[k[i]].size(); j++) {
            if(graph[k[i]][j].to == k[i+1]) {
                ans += graph[k[i]][j].cost;
                break;
            }
        }
    }
    // cout << ans << " " << dist[N-1] << " " << dist2[N-1] << endl;
    if(ans >= dist2[N-1]) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
