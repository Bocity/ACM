#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x ; i < n; ++i)
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
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

int main(){
    int n = 0;
    //ios::sync_with_stdio(0);
    while(read(n)){
        REP(i,0,n){
            read(a[i]);
        }
        REP(i,0,n){
            read(b[i]);
            c[i] = a[i] - b[i];
            //cout << c[i];
        }
        int ans3 = 0;
        int ans4 = 0;
        REP(i,0,n){
            if (c[i]>=0){
                int j = i;
                int ans = 0;
                int ans2 = 0;
                while(ans + c[j] >= 0){
                    ans += c[j];
                    ans2 += a[j];
                    j++;
                    if (j >= n){
                        j = 0;
                    }
                    if (j == i - 1){
                        break;
                    }
                }
                ans2 += a[j];
                if (ans2  > ans3){
                    ans4 = i;
                    ans3 = ans2;
                }
                if (j <= i) break;
                i = j;
                //cout << i << endl;
            }
        }
        printf("%d\n",ans4);
    }
    return 0;
}