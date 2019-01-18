#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
struct node {
    int x, y;
    node(int xx, int yy):x(xx),y(yy){}
};
node tofind(int n, int m) {
    if(n == 2) {
        if(m == 1) return node(1, 1);
        if(m == 2) return node(1, 2);
        if(m == 3) return node(2, 2);
        if(m == 4) return node(2, 1);
    }
    int kk = n * n / 4;
    node d(0, 0);
    if(m <= kk) {
        d = tofind(n/2, m % kk);
        swap(d.x, d.y);
    }
    else if(m <= kk * 2) {
        d = tofind(n/2, m % kk);
        d.y += n / 2;
    }
    else if(m <= 3 * kk) {
        d = tofind(n/2, m % kk);
        d.x += n / 2;
        d.y += n / 2;
    }
    else {
        d = tofind(n/2, m % kk);
        swap(d.x, d.y);
        d.x = n - d.x + 1;
        d.y = n/2 - d.y + 1;
    }
    return d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    node ans = tofind(n, m);
    cout << ans.x << ' ' << ans.y << endl;
    return 0;
}