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

    int pos = 0;
    long long ans = 1;
    while (a[pos] == a[pos+1] ){
        pos++;
        ans++;
    }
    long long x = a[pos+1],y = a[pos];
    REP(i,pos+1,n){
        if (a[i]!= x && a[i] != y){
            anss = max(anss,ans);
            ans = 2;
            x = a[i];
            y = a[i-1];
        }else{
            ans++;
        }
    }
    cout << max(anss,ans);
    return 0;
}