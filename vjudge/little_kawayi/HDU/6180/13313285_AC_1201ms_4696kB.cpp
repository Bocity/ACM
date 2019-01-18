#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
typedef long long ll;
using namespace std;
struct node{
    int x;
    int y;
};
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
node q[100005];
int t;
multiset<int> seq;
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        seq.clear();
        REP(i,0,n){
            int x,y;
            cin >> x >> y;
            node tmp;
            tmp.x = x;
            tmp.y = y;
            q[i] = tmp;
        }
        sort(q,q+n,cmp);
        ll anss = 0;
                ll ans =0;
        REP (i,0,n) {
            auto tmp =  seq.upper_bound(q[i].x) ;   // 此处使用 lower_bound() 进行二分搜索
            if (tmp == seq.begin()){
                seq.insert(q[i].y);
                anss++;
                ans+=q[i].y - q[i].x;
            }else{
                tmp--;
                ans+=q[i].y - *tmp;
                seq.erase(tmp);
                seq.insert(q[i].y);
            }
        }

        cout << anss<<" "<<ans << endl;
        //cout << ans << endl;
    }
    return 0;
}