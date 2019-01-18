#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
struct node{
    int x;
    int y;
};
bool operator < (node x,node y){
    return x.y < y.x;
}
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
vector<pii> q;
vector<int> v2;
map<int,int> vis;
int t;
int main(){
    int n;
    read(t);
    while(t--){
		vis.clear();
        read(n);
        q.clear();
        REP(i,0,n){
            int x,y;
            read(x);
            read(y);
            q.push_back(pii(x,y));
        }
        sort(q.begin(),q.end());
        int ans = 0;
        int ans2 = 0;
        int ans3 = 0;
        priority_queue<int,vector<int>,greater<int>>p;
        priority_queue<int,vector<int>,greater<int>>Q;
        REP(i,0,q.size()){
            if (!p.empty() && q[i].first > p.top()){
                while(!p.empty() && q[i].first > p.top()){
                    p.pop();
                    ans2++;
                }
            }else{
                //cout << "fuck";
                if (ans2!=0){
                    ans2--;
                }else{
                    ans++;
                    Q.push(q[i].first);
                }
            }
            p.push(q[i].second);
			vis[q[i].second] = i;
        }
		v2.clear();
		REP(i,0,ans){
			v2.push_back(p.top());
			p.pop();
		}
		sort(v2.begin(),v2.end(),[&](int x,int y){return vis[x] < vis[y];});
        REP(i,0,ans){
            ans3+=v2[i]-Q.top();
            Q.pop();
        }
        printf("%d %d\n",ans,ans3);

        //cout << ans << endl;
    }
    return 0;
}