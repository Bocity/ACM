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
int ans1 = 0;
int ans2 = 0;
void dfs(int rt,int ran){
        if (ran) ans1++;
        else ans2++;
        vis[rt] = ran;
        REP(i,0,a[rt].size()){
            if (!(~vis[a[rt][i]])){
                dfs(a[rt][i],ran ^ 1);
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
        mems(vis,-1);
        REP(i,0,100001) a[i].clear();
        read(n);
        read(k);
        REP(i,1,n){
            read(m);
            a[m].push_back(i+1);
            a[i+1].push_back(m);
        }
        dfs(1,0);
        //cout << ans1 <<" "<<ans2 << endl;
        int minn = min(ans1,ans2);
        if (k/2 > minn){
            printf("%d\n",(k - minn * 2));
        }else{
            printf("%d\n",(k+1)/2);
        }
    }
   return 0;
}