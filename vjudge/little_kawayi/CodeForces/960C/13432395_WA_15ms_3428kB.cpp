#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 10000 + 10;
const ll MOD = 1e9+7;

ll x, d;
ll a[maxn], rcd[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll f = 2;
    ll sum = 0;
    for(int i = 1; i < 64; i++) {
        a[i] = f - 1;
        f *= 2;
        // cout << a[i] << " ";
    }
    cin >> x >> d;
    int p = 0;
    for(int i = 63; i > 0; i--) {
        while(x >= a[i]) {
            rcd[p++] = i;
            x -= a[i];
            sum += i;
            // cout << "X " << x << " ";
            // cout << "i " << i << " ";
        }
        if(x == 0) break;
    }
    // cout << endl;
    // for(int i = 0; i < p; i++) cout << rcd[i] << " ";
    ll num = 1;
    cout << sum << endl;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < rcd[i]; j++) {
            cout << num++ << " ";
        }
        num += d;
    }
    return 0;
}