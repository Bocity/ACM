#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
long long a[10000] = {0};
int main(){
    long long  n;
    long long anss = -1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    REP(i,0,n){
        cin >> a[i];
    }
    long long x = a[0],y = a[1];
    long long ans = 2;
    REP(i,2,n){
        if (a[i]!= x && a[i] != y){
            x = a[i-1];
            y = a[i];
            anss = max(anss,ans);
            ans = 2;
        }else{
            ans++;
        }
    }
    cout << max(anss,ans);
    return 0;
}