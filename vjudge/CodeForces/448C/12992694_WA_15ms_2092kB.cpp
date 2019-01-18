#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
long long a[10000] = {0};
long long dfs(long long l,long long r){
    //cout << l << " " << r << endl;
    if (l > r) return 0;
    long long ans = 1e10;
    long long anss = 0;
    REP(i,l,r+1){
      ans = min(a[i],ans);
    }
    if (ans > r-l+1){
        return r-l+1;
    }
    REP(i,l,r+1){
        a[i] -= ans;
    }
    long long spos = l;
    REP(i,l,r+1){
        if (a[i] == 0){
            anss += dfs(spos,i-1);
            spos=i+1;
        }
    }
    return anss + ans;
}
int main(){
    long long  n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long sum = 0;
    long long minn = 1e10;
    long long ans;
    REP(i,0,n){
        cin >> a[i];
        minn = min(a[i],minn);
        sum += a[i];
    }
    if (minn >= n){
            cout << n << endl;
            return 0;
    }
    cout << min(dfs(0,n-1),n);
    return 0;
}