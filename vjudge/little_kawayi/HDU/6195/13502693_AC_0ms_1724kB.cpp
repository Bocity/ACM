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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m, k;
    while(cin >> m >> k) {
        cout << (m - k + 1) * k << endl;
    }
    return 0;
}