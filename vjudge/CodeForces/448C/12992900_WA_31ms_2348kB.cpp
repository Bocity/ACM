#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
long long a[10000] = {0};
long long dfs(long long l,long long r){
   // cout << l << " " << r << endl;
    if (l >= r) return 0;
    long long ans = 1e10;
    long long anss = 0;
    REP(i,l,r){
      ans = min(a[i],ans);
    }
    REP(i,l,r){
        a[i] -= ans;
    }
    long long spos = l;
    REP(i,l,r){
        if (a[i] == 0 || i == r-1){
            anss += dfs(spos,i);
            spos=i+1;
        }
    }
    return min(anss + ans,r-l);
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
    }
    cout << dfs(0,n);
    return 0;
}