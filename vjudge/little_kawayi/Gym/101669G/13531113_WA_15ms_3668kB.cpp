#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= x; --i)
#define endl "\n"
using namespace std;
typedef long long ll;
int n,k;
string s,s1;
struct node{
    ll x,y,sum;
}a[10005];
bool cmp(node x,node y){
    return x.sum > y.sum;
}
double calc(){
    double v = 0;
    double ans = 0;
    REP(i,0,n){
        ans += v * a[i].y + 0.5 * a[i].x * a[i].y * a[i].y;
        v += a[i].sum;
    }
    return ans;
}
main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i,0,n){
        cin >> a[i].x >> a[i].y;
        a[i].sum = a[i].x * a[i].y;
    }
    double ans = 0;
    ans = calc();
    sort(a,a+n,cmp);
    ans = calc() - ans;
    cout << setprecision(1) << fixed << ans << endl;
}