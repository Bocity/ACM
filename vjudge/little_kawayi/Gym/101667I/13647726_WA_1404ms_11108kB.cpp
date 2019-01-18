#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int dp[1000005];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;++i){
        cin >> f[i];
    }
    dp[n] = 1;
    for(int i = n-1; i>=1; --i){
        if (f[i + dp[i + 1]] == f[i]){
            dp[i] = dp[i + 1];
        }else{
            dp[i] = n-i;
        }
    }
    // for(int i = 1; i <= n; ++i){
    //     cout << dp[i] << " ";
    // }
    int ans = 1000005;
    int x,y;
    for(int i = 0 ; i < n; i++){
       if ((i + dp[i + 1]) < ans ){
           ans = i + dp[i + 1];
           x = i;
           y = dp[i+1];
       }
    }
    cout << x << " " << y << endl;
    return 0;
}