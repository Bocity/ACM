#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= x; --i)
#define endl "\n"
using namespace std;
typedef long long ll;
int n,k;
string s,s1;
struct node{
    double x,y,sum;
}a[100005];
bool cmp(node x,node y){
    if (x.sum == y.sum) return x.y < y.y;
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
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i,0,n){
        cin >> a[i].x >> a[i].y;
        a[i].sum = a[i].x * a[i].y;
    }
    double ans = 0;
  //  REP(i,0,n) cout << a[i].x << " " << a[i].y << endl;
    ans = calc();
    sort(a,a+n,cmp);
 //   REP(i,0,n) cout << a[i].x << " " << a[i].y << endl;
    ans = calc() - ans;
    cout << setprecision(1) << fixed << ans << endl;
    return 0;
}