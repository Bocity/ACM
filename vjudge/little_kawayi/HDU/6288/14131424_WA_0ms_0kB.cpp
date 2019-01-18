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
        tmp *= x;
    }
    REP(i,0,b){
        tmp *= ceil(log2((double)x));
    }
    return tmp;
}
void stay(){
    //cin >> n >> m >> k;
    cin >> a >> b >> k;
    ll l = 0,r = pow(k,1.0/a);
    ll mid = 0;
    while (l <= r){
        mid = l + (r - l) / 2;
       // cout << mid <<" "<<check(mid) <<endl;
        if (check(mid) <= k){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << r << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> t;
    //cout << 1e15 * log2(1e15) << endl;
    while(t--){
        stay();
    }
    return 0;
}