#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[10000005]{0};
int dp[10000005]{0};
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;++i){
        cin >> f[i];
    }
    dp[n] = 1;
    for(int i = n-1; i >= 1; --i){
        if (f[i + dp[i + 1]] == f[i]){
            dp[i] = dp[i + 1];
        }else{
            dp[i] = n - i + 1;
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << dp[i] << " ";
    }
    int ans = 100000000005;
    int x,y;
    for(int i = 0 ; i < n; i++){
       if ((i + dp[i + 1]) < ans ){
           ans = i + dp[i + 1];
           x = i;
           y = dp[i+1];
       }
    }
    if (n < ans){
        cout << n << " " << 0 << endl;
    }else
        cout << x << " " << y << endl;
    return 0;
}