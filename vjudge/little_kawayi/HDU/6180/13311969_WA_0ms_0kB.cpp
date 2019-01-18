#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
struct node{
    int x;
    int y;
};
bool operator==(node x,node y){
    return x.x==y.x && x.y==y.y;
}
bool operator < (node x,node y){
    return x.y > y.x;
}
#define pii pair<int,int>
        node seq[1000000]{0};
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
vector<node> q;
int dp[100000]{0};
int t;
        queue<int>qq;
int main(){
    int n;
    read(t);
    while(t--){
        read(n);
        q.clear();
        while(!qq.empty())qq.pop();
        REP(i,0,n){
            int x,y;
            read(x);
            read(y);
            node tmp;
            tmp.x = x;
            tmp.y = y;
            q.push_back(tmp);
        }
        // sort(q.begin(),q.end());

        int pos = 0;
        int len = 0;
        node zero;
        zero.x = 0;
        zero.y = 0;

        REP (i,0,n) {
            pos = lower_bound(seq, seq+len, q[i]) - seq;    // 此处使用 lower_bound() 进行二分搜索
            if (seq[pos] == zero){
                qq.push(q[i].x);
            }
            seq[pos] = q[i];
            len = max(len, pos + 1);    // 是否成为最大的元素使 LIS 增长，如无，则保留原来的长度
            dp[i] = len;
        }
        int ans = 0;
        REP(i,0,len){
            ans += seq[i].y-qq.front();
            qq.pop();
        }
        printf("%d %d\n", dp[n-1],ans);
        //cout << ans << endl;
    }
    return 0;
}