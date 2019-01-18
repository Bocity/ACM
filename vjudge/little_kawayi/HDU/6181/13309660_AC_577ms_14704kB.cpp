#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define INF 0x3f3f3f3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int MAXN = 100000 + 10;

using namespace std;

struct edge{
    ll to, cost;
    edge(ll tv = 0, ll tc = 0):
        to(tv), cost(tc){}
};
typedef pair<ll, ll> P;
int N, R;
vector<edge> graph[MAXN];
ll dist[MAXN];
ll dist2[MAXN];

void solve() {
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    priority_queue<P, vector<P>, greater<P> > Q;
    dist[0] = 0;
    Q.push(P(0, 0));
    while(!Q.empty()){
        P p = Q.top(); 
        Q.pop();
        ll v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        for(ll i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            ll d2 = d + e.cost;
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
    printf("%lld\n", dist2[N-1]);
}

int main(){
    int A, B, D, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &R);
        for(int i = 0; i < R; i++) graph[i].clear();
        for(int i = 0; i < R; i++){
            scanf("%d%d%d", &A, &B, &D);
            graph[A-1].push_back(edge(B-1, D));
            graph[B-1].push_back(edge(A-1, D));
        }
        solve();
    }
    return 0;
}