#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
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
struct plan
{
    int s;
    int t;
    friend bool operator < (plan x,plan y)
    {
        return x.t < y.t || (x.t == y.t && x.s < y.s);
    }
};
int main(){

    int t;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        plan *p = new plan[n];
        int *nxt = new int[n];
        for (int i = 0; i < n; i++)
            nxt[i] = i+1;
        for (int i = 0; i < n; i++)
        {
            read(p[i].s);
            read(p[i].t);
        }
        sort(p, p + n);
        int cnt = 0,ans = 0,lst = n,st = 0, ed = n-1;
        while(lst)
        {
            int b = -1;
            int e = 0;
            for (int i = st; i <= ed; i = nxt[i])
                if (p[i].s > e)
                {
                    if (i != ed && i != st)
                        nxt[i] = nxt[nxt[i]];
                    else if (i == ed)
                        ed--;
                    else
                        st++;
                    e = p[i].t;
                    if (b == -1)
                        b = p[i].s;
                    lst--;
                }
            ans+= e - b;
            cnt++;
        }
        printf("%d %d",cnt,ans);
    }
    return 0;
}