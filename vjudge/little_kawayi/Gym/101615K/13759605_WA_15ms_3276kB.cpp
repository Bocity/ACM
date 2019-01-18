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
const int maxn = 1000000 + 10;
int tofind(int a, int b) {
    int x = abs(a - b);
    int y = 10 - x;
    if(x > y) return y;
    return x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ss;
    cin >> ss;
    int l = ss.length();
    int ans = 0;
    for(int i = 0, j = l - 1; i < j; i++, j--) {
        int a = ss[i] - '0';
        int b = ss[j] - '0';
        ans += tofind(a, b);
    }
    cout << ans << endl;
    return 0;
}