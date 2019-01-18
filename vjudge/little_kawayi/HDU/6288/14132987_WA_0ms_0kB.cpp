#include <bits/stdc++.h>
#define REP(i,x,n) for(int i= x;i < n; ++i)
#define endl "\n"
#define maxn  10005
using namespace std;
typedef unsigned long long ll;
int t;
int a,b;
ll k;
ll check(ll x){
    ll tmp = 1;
    REP(i,0,a){
        if (tmp > 1e18 / x)return (ll)1e18 + 1;
        tmp *= x;

    }
    ll p = 1;
    ll ans = 0;
    while (p < x){
        ans ++;
        p*=2;
    }
    REP(i,0,b){
        if (tmp > 1e18/ ans) return (ll)1e18 + 1;
        tmp *= ans;
    }
    return tmp;
}
void stay(){
    //cin >> n >> m >> k;
    cin >> a >> b >> k;
    ll l = 0,r = 1e18;
    ll mid = 0;
    cout << r << endl;
    while (l < r){
        mid = l + r + 1 >> 1;
       //cout << mid <<" "<<check(mid) <<endl;
        if (check(mid) <= k){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << l << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> t;
   // cout << 18181818181818181 * (ll)ceil(log2(18181818181818181)) << endl;
    //cout << 1e15 * log2(1e15) << endl;
    while(t--){
        stay();
    }
    return 0;
}