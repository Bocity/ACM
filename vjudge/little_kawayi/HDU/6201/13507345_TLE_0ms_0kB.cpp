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
namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline bool read(auto &x) {
    char ch;
    bool ne = false;
    while (blank(ch = nc()))
        ;
    if (IOerror) return false;
    if (ch == '-') ne = true, ch = nc();
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
    if (ne) x = -x;
    return true;
}
#undef BUF_SIZE
};
using namespace fastIO;
void dfs(int rt,int fa){
    REP(i,0,e[rt].size()){
            if (e[rt][i].first == fa)continue;
            vis[e[rt][i].first] = 1;
            dfs(e[rt][i].first,rt);
            max1[rt] = max(max1[rt],max(max1[e[rt][i].first] - e[rt][i].second,-cost[rt]));
            max2[rt] = max(max2[e[rt][i].first] - e[rt][i].second,max2[rt]);
    }
}
int n;
void init(){
    REP(i,0,n+1){
        max1[i] = -INF;
        max2[i] = 0;
        e[i].clear();
    }
    memset(vis,0,sizeof vis);
}
void stay(){
    int w;
    init();
    read(n);
    REP(i,0,n){
        read(w);
        cost[i+1] = w;
    }
    int x,y;
    REP(i,0,n-1){
        read(x);
        read(y);
        read(w);
        e[x].push_back(pii(y,w));
        e[y].push_back(pii(x,w));
    }
    dfs(1,-1);
    int ans = 0;
    REP(i,1,n + 1){
        if (i == 1 && e[i].size() == 1 ) continue;
        if (i!=1 && e[i].size() <= 2) continue;
       // cout << i<<" "<<max1[i] << " " << max2[i] << endl;
        ans = max(max(max1[i]+max2[i],ans),cost[i]+max1[i]);
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    read(t);
    while(t--){
        stay();
    }
    return 0;
}