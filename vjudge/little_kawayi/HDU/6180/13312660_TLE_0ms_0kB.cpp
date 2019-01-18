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
bool operator<(node x,node y){
    return x.y>y.x;
}
bool cmp(node x,node y){
    if (x.x == y.x)return x.y < y.y;
    return x.x < y.x;
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
vector<node> q;
int t;
set<node> seq;
int main(){
    int n;
    read(t);
    while(t--){
        read(n);
        seq.clear();
        q.clear();
        REP(i,0,n){
            int x,y;
            read(x);
            read(y);
            node tmp;
            tmp.x = x;
            tmp.y = y;
            q.push_back(tmp);
        }
        sort(q.begin(),q.end(),cmp);
        REP (i,0,n) {
            auto tmp =  lower_bound(seq.begin(), seq.end(), q[i]) ;   // 此处使用 lower_bound() 进行二分搜索
            if (tmp == seq.end()){
                seq.insert(q[i]);
            }else{
                node temp = *tmp; 
                q[i].y = max(temp.y,q[i].y);
                q[i].x = min(temp.x,q[i].x);
                seq.erase(tmp);
                seq.insert(q[i]);
            }
        }
        int ans =0;
        for(auto &x:seq){
            ans += x.y - x.x;
        }
        printf("%d %d\n",seq.size(),ans);
        //cout << ans << endl;
    }
    return 0;
}