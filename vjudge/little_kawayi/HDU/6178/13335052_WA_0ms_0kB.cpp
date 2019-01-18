#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define mems(a,n) memset(a,n,sizeof a)
typedef long long ll;
using namespace std;
#define pii pair<int,int>
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x =(x<<1)+(x<<3) + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;
vector<int> a[100005];
int vis[100005];
int vis2[100005];
int ans1 = 0;
int ans2 = 0;
void dfs(int rt,int from){
    if (!vis2[from]&& !vis2[rt]){
        vis2[rt] = 1;
        vis2[from] = 1;
        ans1 ++;
    }
    vis[rt] = 1;
    REP(i,0,a[rt].size()){
        if (!vis[a[rt][i]]){
            dfs(a[rt][i],rt);
        }
    }

}
int main(){
    int n,m,k;
    int t;
    //ios::sync_with_stdio(0);
    read(t);
    while(t--){
        ans1 = ans2 = 0;
        mems(vis,0);
        mems(vis2,0);
        REP(i,0,100001) a[i].clear();
        read(n);
        read(k);
        REP(i,1,n){
            read(m);
            a[m].push_back(i+1);
            a[i+1].push_back(m);
        }
        REP(i,0,a[2].size()){
            dfs(a[2][i],2);
        }
        //cout << ans1 <<" "<<ans2 << endl;
        if (ans1*2 > k){
            printf("%d\n",(k+1)/2);
        }else{
            printf("%d\n",k-ans1);
        }
    }
   return 0;
}